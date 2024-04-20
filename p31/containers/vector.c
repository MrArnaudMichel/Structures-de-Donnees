//
// Created by arnau on 14/11/2023.
//

#include "vector.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>


void vec_init(vector *v, size_t value_size){
    v->size = 0;
    v->capacity = 8;
    v->value_size = value_size;
    v->data = NULL;
    vec_reserve(v, v->capacity);
}

void vec_free(vector *v){
    v->capacity = 0;
    v->size = 0;
    v->value_size = 0;
    free(v->data);
}

size_t vec_size(vector const *v){
    return v->size;
}
size_t vec_value_size(vector const *v){
    return v->value_size;
}
size_t vec_capacity(vector const *v){
    return v->capacity;
}

void vec_reserve(vector *v, size_t nb_values){
    if (v->capacity > nb_values){
        return;
    }
    v->data = realloc(v->data, (nb_values) * v->value_size);
    v->capacity = nb_values;
}

// retourne un pointeur sur la case d'index index
void const *vec_get_pointer(vector const *v, size_t index){
    return ((char *) v->data + index * v->value_size);
}
// copie la valeur contenue dans la case d'index index à l'adresse pointée par value
void vec_get_value(vector const *v, size_t index, void *value){
    memcpy(value, vec_get_pointer(v, index), v->value_size);
    return;
}

// copie la mémoire pointée par value dans la case d'index index
void vec_set_value(vector *v, size_t index, void const *value) {
    const void *ptr = vec_get_pointer(v, index);
    assert(ptr != NULL);
    memcpy((void *)ptr, value, v->value_size);
}

// copie la mémoire pointée par value dans une nouvelle case à la fin du vector v
void vec_push_back(vector *v, void const *value){
    if (v->capacity == v->size){
        vec_reserve(v, v->capacity * 2);
    }
    vec_set_value(v, v->size, value);
    v->size++;
    return;
}

// copie la mémoire pointée par value dans une nouvelle case au début du vector v
void vec_push_front(vector *v, void const *value) {
    if (v->capacity == v->size) {
        vec_reserve(v, v->capacity * 2);
    }
    for (size_t i = v->size; i > 0; --i) {
        vec_set_value(v, i, vec_get_pointer(v, i - 1));
    }
    vec_set_value(v, 0, value);
    v->size++;
    return;
}

void vec_erase(vector *v, size_t index){
    for (size_t i = 0; i < v->size - index; ++i) {
        vec_set_value(v, index + i, vec_get_pointer(v, index + i + 1));
    }
    v->size--;
    return;
}

void vec_swap(vector *v, size_t index1, size_t index2){
    void *tmp = malloc(v->value_size);
    vec_get_value(v, index1, tmp);
    vec_set_value(v, index1, vec_get_pointer(v, index2));
    vec_set_value(v, index2, tmp);
    free(tmp);
}

bool equals_float(void const *a, void const *b)
{
    float f1 = *(float const *)a;
    float f2 = *(float const *)b;
    return f1 == f2;
}

size_t vec_find(vector const *v, void const *value, bool (*equals)(void const *a, void const *b)){
    for (size_t i = 0; i < v->size; ++i) {
        if (equals(vec_get_pointer(v, i), value)){
            return i;
        }
    }
    return ULONG_MAX;
}