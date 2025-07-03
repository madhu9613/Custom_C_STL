#include "avl_map.h"
#include <stdlib.h>
#include <stddef.h>     // ✅ Required for NULL


typedef struct AVLMapNode {
    void* key;
    void* value;
    struct AVLMapNode *left, *right;
    int height;
} AVLMapNode;

struct AVLMap {
    AVLMapNode* root;
    int (*cmp)(const void*, const void*);
};

int height(AVLMapNode* node) {
    return node ? node->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLMapNode* new_node(void* key, void* value) {
    AVLMapNode* node = malloc(sizeof(AVLMapNode));
    node->key = key; node->value = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

AVLMapNode* right_rotate(AVLMapNode* y) {
    AVLMapNode* x = y->left;
    AVLMapNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLMapNode* left_rotate(AVLMapNode* x) {
    AVLMapNode* y = x->right;
    AVLMapNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int get_balance(AVLMapNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLMapNode* insert_node(AVLMapNode* node, void* key, void* value, int (*cmp)(const void*, const void*)) {
    if (!node) return new_node(key, value);

    if (cmp(key, node->key) < 0)
        node->left = insert_node(node->left, key, value, cmp);
    else if (cmp(key, node->key) > 0)
        node->right = insert_node(node->right, key, value, cmp);
    else {
        node->value = value;
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = get_balance(node);

    if (balance > 1 && cmp(key, node->left->key) < 0)
        return right_rotate(node);
    if (balance < -1 && cmp(key, node->right->key) > 0)
        return left_rotate(node);
    if (balance > 1 && cmp(key, node->left->key) > 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && cmp(key, node->right->key) < 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void* find_node(AVLMapNode* node, void* key, int (*cmp)(const void*, const void*)) {
    if (!node) return NULL;
    int res = cmp(key, node->key);
    if (res < 0) return find_node(node->left, key, cmp);
    if (res > 0) return find_node(node->right, key, cmp);
    return node->value;
}

AVLMap* avl_map_create(int (*cmp)(const void*, const void*)) {
    AVLMap* map = malloc(sizeof(AVLMap));
    map->root = NULL;
    map->cmp = cmp;
    return map;
}

void avl_map_insert(AVLMap* map, void* key, void* value) {
    map->root = insert_node(map->root, key, value, map->cmp);
}

void* avl_map_get(AVLMap* map, void* key) {
    return find_node(map->root, key, map->cmp);
}
