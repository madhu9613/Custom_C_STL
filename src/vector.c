#include "vector.h"
#include <stdlib.h>

Vector* vector_create() {
    Vector* v = malloc(sizeof(Vector));
    v->size = 0;
    v->capacity = 4;
    v->data = malloc(v->capacity * sizeof(void*));
    return v;
}

void vector_push_back(Vector* v, void* item) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(void*));
    }
    v->data[v->size++] = item;
}

void* vector_at(Vector* v, size_t index) {
    if (index >= v->size) return NULL;
    return v->data[index];
}

void vector_free(Vector* v) {
    free(v->data);
    free(v);
}
