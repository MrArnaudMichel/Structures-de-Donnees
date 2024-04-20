//
// Created by arnaud on 19/12/2023.
//

#include "heap_sort.h"

void heap_sort_vec(vector *v,
                   int (*compare)(void const *a, void const *b)){
    heap h;
    heap_init(&h, v->value_size, compare);
    heap_build((heap *) v);
    for (size_t i = v->size - 1; i > 0; i--){
        void *tmp = malloc(v->value_size);
        memcpy(tmp, ((char *) v->data + i * v->value_size), v->value_size);
        memcpy(((char *) v->data + i * v->value_size),
               ((char *) v->data), v->value_size);
        memcpy(((char *) v->data), tmp, v->value_size);
        free(tmp);
        v->size--;
        heap_send_down((heap *) v, 0);
    }
    heap_free(&h);
}
