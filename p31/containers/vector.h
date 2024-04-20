//
// Created by arnau on 14/11/2023.
//

#ifndef P31_VECTOR_H
#define P31_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    size_t size;
    size_t capacity;
    size_t value_size;
    void *data;
}vector;

void vec_init(vector *v, size_t value_size);
void vec_free(vector *v);

size_t vec_size(vector const *v);
size_t vec_value_size(vector const *v);
size_t vec_capacity(vector const *v);

void vec_reserve(vector *v, size_t nb_values);

// retourne un pointeur sur la case d'index index
void const *vec_get_pointer(vector const *v, size_t index);
// copie la valeur contenue dans la case d'index index à l'adresse pointée par value
void vec_get_value(vector const *v, size_t index, void *value);
// copie la mémoire pointée par value dans la case d'index index
void vec_set_value(vector *v, size_t index, void const *value);
// copie la mémoire pointée par value dans une nouvelle case à la fin du vector v
void vec_push_back(vector *v, void const *value);
// copie la mémoire pointée par value dans une nouvelle case au début du vector v
void vec_push_front(vector *v, void const *value);
void vec_erase(vector *v, size_t index);

void vec_swap(vector *v, size_t index1, size_t index2);
size_t vec_find(vector const *v, void const *value,
                bool (*equals)(void const *a, void const *b));

bool equals_float(void const *a, void const *b);

#endif //P31_VECTOR_H
