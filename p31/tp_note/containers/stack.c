#include "stack.h"

#include <string.h>
#include <assert.h>

void stack_init(stack *s, size_t value_size)
{
    vec_init(&s->v, value_size);
}

void stack_free(stack *s)
{
    vec_free(&s->v);
}

size_t stack_size(stack const *s)
{
    return vec_size(&s->v);
}

size_t stack_value_size(stack const *s)
{
    return vec_value_size(&s->v);
}

void stack_push(stack *s, void const *value)
{
    vec_push_back(&s->v, value);

}

void stack_top(stack const *s, void *value)
{
    assert(stack_size(s) > 0);
    memcpy(value, vec_get_pointer(&s->v, stack_size(s) - 1), stack_value_size(s));
}

void stack_pop(stack *s, void *value)
{
    assert(stack_size(s) > 0);
    stack_top(s, value);
    vec_erase(&s->v, stack_size(s) - 1);
}
