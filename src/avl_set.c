#include "avl_set.h"
#include <stddef.h>     // ✅ Required for NULL

AVLSet* avl_set_create(int (*cmp)(const void*, const void*)) {
    return avl_map_create(cmp);
}

void avl_set_insert(AVLSet* set, void* key) {
    avl_map_insert(set, key, NULL);
}

int avl_set_contains(AVLSet* set, void* key) {
    return avl_map_get(set, key) != NULL;
}
