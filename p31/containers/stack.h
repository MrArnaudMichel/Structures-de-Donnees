//
// Created by arnaud on 28/11/2023.
//

#ifndef P31_STACK_H
#define P31_STACK_H

#include <stdlib.h>

typedef struct stack{
    size_t size;
    size_t capacity;
    size_t value_size;
    void *data;
}stack;

void stack_init(stack *s, size_t value_size);
void stack_free(stack *s);

void stack_reserve(stack *s, size_t nb_values);

void stack_push(stack *s, void const *value);
// copie la valeur contenue dans l'élément du sommet de la pile
// à l'adresse pointée par value
void stack_top(stack const *s, void *value);
// copie la valeur contenue dans l'élément du sommet de la pile
// à l'adresse pointée par value, puis supprime cet élément
void stack_pop(stack *s, void *value);

#endif //P31_STACK_H
