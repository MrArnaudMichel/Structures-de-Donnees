//
// Created by arnaud on 28/11/2023.
//

#include "insertion_sort.h"
#include <stdio.h>


void insertion_sort_vec(vector *v, int (*compare)(void const *a, void const *b)) {
    for (size_t i = 1; i < v->size; i++) {
        int *key = malloc(sizeof(int));
        vec_get_value(v, i, key);
        int index = i - 1;
        while (index >= 0 && compare(vec_get_pointer(v, index), key) > 0) {
            memmove((void *)vec_get_pointer(v, index + 1), vec_get_pointer(v, index), v->value_size);
            index--;
        }
        memcpy((void *)vec_get_pointer(v, index + 1), key, v->value_size);
        free(key);
    }
}



void insertion_sort_ll(linked_list *ll,
                       int (*compare)(void const *a, void const *b)) {
    linked_list sorted_ll;
    ll_init(&sorted_ll, ll->value_size);
    while (ll_size(ll) > 0) {
        void *min = ll_get_node(ll, 0)->data;
        size_t min_index = 0;
        for (size_t j = 0; j < ll_size(ll); j++) {
            if (compare(ll_get_node(ll, j)->data, min) < 0) {
                min = ll_get_node(ll, j)->data;
                min_index = j;
            }
        }
        ll_push_back(&sorted_ll, min);
        ll_erase_node(ll, (linked_list_node *)ll_get_node(ll, min_index));
    }
    ll_free(ll);
    *ll = sorted_ll;
}
