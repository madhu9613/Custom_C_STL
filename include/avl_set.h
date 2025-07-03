#pragma once
#include "avl_map.h"

typedef AVLMap AVLSet;

AVLSet* avl_set_create(int (*cmp)(const void*, const void*));
void avl_set_insert(AVLSet* set, void* key);
int avl_set_contains(AVLSet* set, void* key);
