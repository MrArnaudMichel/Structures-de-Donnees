//
// Created by arnaud on 12/12/2023.
//

#include "heap.h"
#include "vector.h"

void heap_init(heap *h, size_t value_size,
               int (*compare)(void const *a, void const *b)){
    vec_init((vector *) h, value_size);
    h->compare = compare;
}
void heap_free(heap *h){
    vec_free((vector *) h);
}

size_t heap_size(heap const *h){
    return h->size;
}
size_t heap_value_size(heap const *h){
    return h->value_size;
}

size_t heap_left_child(size_t i){
    return 2 * i + 1;
}
size_t heap_right_child(size_t i){
    return 2 * i + 2;
}
size_t heap_parent(size_t i){
    return (i - 1) / 2;
}

void heap_send_up(heap *h, size_t i){
    size_t parent = heap_parent(i);
    while (i > 0 && h->compare(((char *) h->data + i * h->value_size),
                               ((char *) h->data + parent * h->value_size)) > 0){
        void *tmp = malloc(h->value_size);
        memcpy(tmp, ((char *) h->data + i * h->value_size), h->value_size);
        memcpy(((char *) h->data + i * h->value_size),
               ((char *) h->data + parent * h->value_size), h->value_size);
        memcpy(((char *) h->data + parent * h->value_size), tmp, h->value_size);
        free(tmp);
        i = parent;
        parent = heap_parent(i);
    }
}
void heap_send_down(heap *h, size_t i){
    size_t left_child = heap_left_child(i);
    size_t right_child = heap_right_child(i);
    size_t max = i;
    if (left_child < h->size &&
        h->compare(((char *) h->data + left_child * h->value_size),
                   ((char *) h->data + max * h->value_size)) > 0){
        max = left_child;
    }
    if (right_child < h->size &&
        h->compare(((char *) h->data + right_child * h->value_size),
                   ((char *) h->data + max * h->value_size)) > 0){
        max = right_child;
    }
    if (max != i){
        void *tmp = malloc(h->value_size);
        memcpy(tmp, ((char *) h->data + i * h->value_size), h->value_size);
        memcpy(((char *) h->data + i * h->value_size),
               ((char *) h->data + max * h->value_size), h->value_size);
        memcpy(((char *) h->data + max * h->value_size), tmp, h->value_size);
        free(tmp);
        heap_send_down(h, max);
    }
}

void heap_insert(heap *h, void const *value){
    if (h->capacity == h->size){
        vec_reserve((vector *) h, h->capacity * 2);
    }
    memcpy(((char *) h->data + h->size * h->value_size), value, h->value_size);
    h->size++;
    heap_send_up(h, h->size - 1);
}

void heap_max(heap const *h, void *value){
    memcpy(value, h->data, h->value_size);
}
void heap_extract(heap *h, void *value){
    heap_max(h, value);
    memcpy(h->data, ((char *) h->data + (h->size - 1) * h->value_size), h->value_size);
    h->size--;
    heap_send_down(h, 0);
}

void heap_build(heap *h){
    for (size_t i = h->size / 2; i > 0; i--){
        heap_send_down(h, i);
    }
}
