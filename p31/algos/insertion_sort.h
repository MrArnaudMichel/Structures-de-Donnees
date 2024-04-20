//
// Created by arnaud on 28/11/2023.
//

#ifndef P31_INSERTION_SORT_H
#define P31_INSERTION_SORT_H

#include "../containers/vector.h"
#include "../containers/linked_list.h"

void insertion_sort_vec(vector *v,
                        int (*compare)(void const *a, void const *b));
void insertion_sort_ll(linked_list *ll,
                       int (*compare)(void const *a, void const *b));

#endif //P31_INSERTION_SORT_H
