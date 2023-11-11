#pragma once

#include <stdlib.h>

typedef struct vector_int
{

} vector_int;

void vec_int_init(vector_int *v);
void vec_int_free(vector_int *v);

size_t vec_int_size(vector_int const *v);
size_t vec_int_capacity(vector_int const *v);

void vec_int_reserve(vector_int *v, size_t nb_values);

int vec_int_get_value(vector_int const *v, size_t index);
void vec_int_set_value(vector_int *v, size_t index, int value);
void vec_int_push_back(vector_int *v, int value);
void vec_int_push_front(vector_int *v, int value);
void vec_int_erase(vector_int *v, size_t index);

void vec_int_swap(vector_int *v, size_t index1, size_t index2);
size_t vec_int_find(vector_int const *v, int value);
