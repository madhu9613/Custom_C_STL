#include "algorithms.h"
#include <stddef.h>     // ✅ Required for NULL

void swap(void** a, void** b) {
    void* t = *a;
    *a = *b;
    *b = t;
}

int partition(void** arr, int low, int high, int (*cmp)(const void*, const void*)) {
    void* pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (cmp(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(void** arr, int low, int high, int (*cmp)(const void*, const void*)) {
    if (low < high) {
        int pi = partition(arr, low, high, cmp);
        quicksort(arr, low, pi - 1, cmp);
        quicksort(arr, pi + 1, high, cmp);
    }
}

void** lower_bound(void** first, void** last, void* value, int (*cmp)(const void*, const void*)) {
    size_t count = last - first;
    while (count > 0) {
        size_t step = count / 2;
        void** mid = first + step;
        if (cmp(*mid, value) < 0) {
            first = mid + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

void** upper_bound(void** first, void** last, void* value, int (*cmp)(const void*, const void*)) {
    size_t count = last - first;
    while (count > 0) {
        size_t step = count / 2;
        void** mid = first + step;
        if (cmp(*mid, value) <= 0) {
            first = mid + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}
