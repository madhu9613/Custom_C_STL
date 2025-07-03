#pragma once
#include <stdlib.h>

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector_create();
void vector_push_back(Vector* v, void* item);
void* vector_at(Vector* v, size_t index);
void vector_free(Vector* v);
