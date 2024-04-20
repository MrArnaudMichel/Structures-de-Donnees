#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct vector
{
    size_t value_size;
    void *data;
    size_t capacity; // expressed in number of elements
    size_t size;     // expressed in number of elements
} vector;

void vec_init(vector *v, size_t value_size);
void vec_free(vector *v);

size_t vec_size(vector const *v);
size_t vec_value_size(vector const *v);
size_t vec_capacity(vector const *v);

void vec_reserve(vector *v, size_t nb_values);

void const *vec_get_pointer(vector const *v, size_t index);
void vec_get_value(vector const *v, size_t index, void *value);
void vec_set_value(vector *v, size_t index, void const *value);
void vec_push_back(vector *v, void const *value);
void vec_push_front(vector *v, void const *value);
void vec_erase(vector *v, size_t index);

void vec_swap(vector *v, size_t index1, size_t index2);
size_t vec_find(vector const *v, void const *value, bool (*equals)(void const *a, void const *b));
