//
// Created by arnaud on 19/12/2023.
//

#ifndef P31_HEAP_SORT_H
#define P31_HEAP_SORT_H

#include "heap.h"
#include "vector.h"

void heap_sort_vec(vector *v,
                   int (*compare)(void const *a, void const *b));

#endif //P31_HEAP_SORT_H
