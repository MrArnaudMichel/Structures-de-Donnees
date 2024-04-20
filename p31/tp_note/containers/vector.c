#include "vector.h"

#include <string.h>
#include <assert.h>
#include <limits.h>

void vec_init(vector *v, size_t value_size)
{
    v->value_size = value_size;
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
    vec_reserve(v, 8);
}

void vec_free(vector *v)
{
    free(v->data);
    v->value_size = 0;
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}

size_t vec_size(vector const *v)
{
    return v->size;
}

size_t vec_value_size(vector const *v)
{
    return v->value_size;
}

size_t vec_capacity(vector const *v)
{
    return v->capacity;
}

void vec_reserve(vector *v, size_t nb_values)
{
    if (nb_values > v->capacity)
    {
        void *m = realloc(v->data, v->value_size * nb_values);
        if (m)
        {
            v->data = m;
            v->capacity = nb_values;
        }
    }
}

void const *vec_get_pointer(vector const *v, size_t index)
{
    assert(index < v->size);
    return (char *)v->data + (index * v->value_size);
}

void vec_get_value(vector const *v, size_t index, void *value)
{
    assert(index < v->size);
    memcpy(value, vec_get_pointer(v, index), v->value_size);
}

void vec_set_value(vector *v, size_t index, void const *value)
{
    assert(index < v->size);
    void *ptr = (char *)v->data + (index * v->value_size);
    memcpy(ptr, value, v->value_size);
}

void vec_push_back(vector *v, void const *value)
{
    if (v->capacity == v->size)
        vec_reserve(v, v->capacity * 2); // double the capacity of the vector
    if (v->capacity > v->size)           // reserve can fail to allocate more space
    {
        v->size++;
        vec_set_value(v, v->size - 1, value);
    }
}

void vec_push_front(vector *v, void const *value)
{
    if (v->capacity == v->size)
        vec_reserve(v, v->capacity * 2); // double the capacity of the vector
    if (v->capacity > v->size)           // reserve can fail to allocate more space
    {
        v->size++;

        void *ptr = (char *)v->data + (1 * v->value_size);
        // memmove: only 1 system call & takes care of overlapping memory regions
        memmove(ptr, v, v->value_size * (v->size - 1));

        // equivalent to this more manual version:

        // for (size_t i = v->size - 1; i > 0; i--)
        // {
        //     void *ptr = v->data + (i * v->value_size);
        //     memcpy(ptr, vec_get_pointer(v, i - 1), v->value_size);
        // }

        vec_set_value(v, 0, value);
    }
}

void vec_erase(vector *v, size_t index)
{
    assert(index < v->size);
    // if index is the last element, there is nothing to move \o/
    if (index < v->size - 1)
    {
        void *ptr = (char *)v->data + (index * v->value_size);
        // memmove: only 1 system call & takes care of overlapping memory regions
        memmove(ptr, vec_get_pointer(v, index + 1), (v->size - index - 1) * v->value_size);
    }
    v->size--;
}

void vec_swap(vector *v, size_t index1, size_t index2)
{
    assert(index1 < v->size && index2 < v->size);
    char tmp[v->value_size];
    memcpy(tmp, vec_get_pointer(v, index1), v->value_size);
    vec_set_value(v, index1, vec_get_pointer(v, index2));
    vec_set_value(v, index2, tmp);
}

size_t vec_find(vector const *v, void const *value, bool (*equals)(void const *a, void const *b))
{
    for (size_t i = 0; i < v->size; i++)
    {
        if (equals(vec_get_pointer(v, i), value))
            return i;
    }
    return ULONG_MAX;
}
