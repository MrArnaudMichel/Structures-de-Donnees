#pragma once

#include <stdlib.h>

/* implemented with a vector */

#include "vector.h"

typedef struct stack
{
    vector v;
} stack;

void stack_init(stack *s, size_t value_size);
void stack_free(stack *s);

size_t stack_size(stack const *s);
size_t stack_value_size(stack const *s);

void stack_push(stack *s, void const *value);
void stack_top(stack const *s, void *value);
void stack_pop(stack *s, void *value);
