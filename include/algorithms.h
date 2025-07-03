#pragma once
#include <stdlib.h>

void quicksort(void** arr, int low, int high, int (*cmp)(const void*, const void*));
void** lower_bound(void** first, void** last, void* value, int (*cmp)(const void*, const void*));
void** upper_bound(void** first, void** last, void* value, int (*cmp)(const void*, const void*));
