#pragma once

typedef struct AVLMapNode AVLMapNode;
typedef struct AVLMap AVLMap;

AVLMap* avl_map_create(int (*cmp)(const void*, const void*));
void avl_map_insert(AVLMap* map, void* key, void* value);
void* avl_map_get(AVLMap* map, void* key);
