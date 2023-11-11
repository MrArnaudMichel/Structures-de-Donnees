#include "vector_int.h"

#include <string.h>
#include <assert.h>
#include <limits.h>

void vec_int_init(vector_int *v)
{
    // initialise les propriétés du vector v
    // réserve un espace mémoire initial de 8 éléments
}

void vec_int_free(vector_int *v)
{
    // libère la mémoire allouée
    // réinitialise les propriétés du vector v
}

size_t vec_int_size(vector_int const *v)
{
    // retourne la taille du vector v
    return 0;
}

size_t vec_int_capacity(vector_int const *v)
{
    // retourne la capacité du vector v
    return 0;
}

void vec_int_reserve(vector_int *v, size_t nb_values)
{
    // fait en sorte que la capacité du vector v soit d'au moins nb_values
}

int vec_int_get_value(vector_int const *v, size_t index)
{
    // suppose que index est inférieur à la taille du vector v
    // retourne la valeur contenue dans la case index du vector v
    return 0;
}

void vec_int_set_value(vector_int *v, size_t index, int value)
{
    // suppose que index est inférieur à la taille du vector v
    // écrase le contenu dans la case index du vector v avec la valeur value
}

void vec_int_push_back(vector_int *v, int value)
{
    // ajoute une case à la fin du vector v avec la valeur value
}

void vec_int_push_front(vector_int *v, int value)
{
    // ajoute une case au début du vector v avec la valeur value
}

void vec_int_erase(vector_int *v, size_t index)
{
    // suppose que index est inférieur à la taille du vector v
    // supprime la case d'index index
}

void vec_int_swap(vector_int *v, size_t index1, size_t index2)
{
    // suppose que index1 et index2 sont inférieurs à la taille du vector v
    // échange le contenu des cases d'index index1 et index2 du vector v
}

size_t vec_int_find(vector_int const *v, int value)
{
    // retourne l'index de la première case du vector v dont le contenu est la valeur value
    // si aucune case ne contient cette valeur, retourne ULONG_MAX
    return ULONG_MAX;
}
