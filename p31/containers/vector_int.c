#include "vector_int.h"

#include <string.h>
#include <assert.h>
#include <limits.h>

void vec_int_init(vector_int *v)
{
    // initialise les propriétés du vector v
    // réserve un espace mémoire initial de 8 éléments

    v->capacity = 8;
    v->size = 0;
    v->data = NULL;
    vec_int_reserve(v, v->capacity);
}

void vec_int_free(vector_int *v)
{
    // libère la mémoire allouée
    // réinitialise les propriétés du vector v
    v->capacity = 0;
    v->size = 0;
    free(v->data);
}

size_t vec_int_size(vector_int const *v)
{
    // retourne la taille du vector v
    return v->size;
}

size_t vec_int_capacity(vector_int const *v)
{
    // retourne la capacité du vector v
    return v->capacity;
}

void vec_int_reserve(vector_int *v, size_t nb_values)
{
    // fait en sorte que la capacité du vector v soit d'au moins nb_values
    if (v->capacity > nb_values){
        return;
    }
    v->data = realloc(v->data, (nb_values) * sizeof(int));
    v->capacity = nb_values;
}

int vec_int_get_value(vector_int const *v, size_t index)
{
    // suppose que index est inférieur à la taille du vector v
    // retourne la valeur contenue dans la case index du vector v
    assert(index < v->size);
    return v->data[index];
}

void vec_int_set_value(vector_int *v, size_t index, int value)
{
    // suppose que index est inférieur à la taille du vector v
    // écrase le contenu dans la case index du vector v avec la valeur value
    assert(index < v->size);
    v->data[index] = value;
}

void vec_int_push_back(vector_int *v, int value)
{
    // ajoute une case à la fin du vector v avec la valeur value
    if (v->capacity == v->size){
        vec_int_reserve(v, 1);
    }
    v->data[v->size] = value;
    v->size++;
}

void vec_int_push_front(vector_int *v, int value)
{
    // ajoute une case au début du vector v avec la valeur value
    if (v->capacity == v->size){
        vec_int_reserve(v, 1);
    }
    memmove(v->data + 1, v->data, v->size * sizeof(int));
    v->data[0] = value;
}

void vec_int_erase(vector_int *v, size_t index)
{
    // suppose que index est inférieur à la taille du vector v
    // supprime la case d'index index
    assert(index < v->size);
    for (int i = 0; i < v->size - index; i++){
        v->data[i + index] = v->data[i +index+1];
    }
    v->size--;
}

void vec_int_swap(vector_int *v, size_t index1, size_t index2)
{
    // suppose que index1 et index2 sont inférieurs à la taille du vector v
    // échange le contenu des cases d'index index1 et index2 du vector v
    assert(index1 < v->size && index2 < v->size);
    int value = v->data[index1];
    v->data[index1] = v->data[index2];
    v->data[index2] = value;
    return;
}

size_t vec_int_find(vector_int const *v, int value)
{
    // retourne l'index de la première case du vector v dont le contenu est la valeur value
    // si aucune case ne contient cette valeur, retourne ULONG_MAX
    for (int i = 0; i < v->size; ++i) {
        if (v->data[i] == value){
            return i;
        }
    }
    return ULONG_MAX;
}
