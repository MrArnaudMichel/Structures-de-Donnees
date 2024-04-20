#include "bubble_sort.h"
#include "vector_int.h"
#include "vector.h"

#include <stdio.h>

void bubble_sort_vec_int(vector_int *v)
{
    for (size_t i = 0; i < v->size; ++i) {
        for (size_t j = 0; j < v->size - i - 1; ++j) {
            if (vec_int_get_value(v, j) > vec_int_get_value(v, j + 1)) {
                vec_int_swap(v, j, j + 1);
            }
        }
    }
}

void bubble_sort_vec(vector *v, int (*compare)(void const *a, void const *b)){
    for (size_t i = 0; i < v->size; ++i) {
        printf("i = %zu\n", i);
        for (size_t j = 0; j < v->size - i - 1; ++j) {
            printf("j = %zu\n", j);
            if (compare(vec_get_pointer(v, j), vec_get_pointer(v, j + 1)) > 0) {
                vec_swap(v, j, j + 1);
            }
        }
    }
}