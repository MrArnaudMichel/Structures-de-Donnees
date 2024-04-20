#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef struct vector_int vector_int;
typedef struct vector vector;

void bubble_sort_vec_int(vector_int *v);
void bubble_sort_vec(vector *v, int (*compare)(void const *a, void const *b));
