//
// Created by arnaud on 28/11/2023.
//

#include "stack.h"

#include <stdio.h>
#include <string.h>

void stack_init(stack *s, size_t value_size){
    s->capacity = 8;
    s->size = 0;
    s->data = NULL;
    s->value_size = value_size;
    stack_reserve(s, 8);
}
void stack_free(stack *s){
    free(s->data);
    s->value_size = 0;
}

void stack_reserve(stack *s, size_t nb_values){
    if (s->capacity > nb_values){
        return;
    }
    s->data = realloc(s->data, (nb_values) * s->value_size);
    s->capacity = nb_values;
}

void stack_push(stack *s, void const *value) {
    if (s->capacity == s->size){
        stack_reserve(s, s->capacity * 2);
    }
    memcpy(((char *) s->data + s->size * s->value_size), value, s->value_size);
    s->size++;
}


void stack_top(stack const *s, void *value) {
    memcpy(value, ((char *) s->data + (s->size - 1) * s->value_size), s->value_size);
}
void stack_pop(stack *s, void *value) {
    stack_top(s, value);
    s->size--;
}