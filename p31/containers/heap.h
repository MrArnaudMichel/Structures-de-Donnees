//
// Created by arnaud on 12/12/2023.
//

#ifndef P31_HEAP_H
#define P31_HEAP_H

#include <stdlib.h>
#include <string.h>

typedef struct heap {
    size_t capacity;
    size_t size;
    void *data;
    size_t value_size;
    int (*compare)(void const *a, void const *b);
} heap;

// en plus de la taille des éléments, on fournit également un pointeur vers une
// fonction de comparaison d'éléments, à stocker dans la structure
// (cette fonction est une donnée essentielle du tas car elle permet de définir
// la propriété de tas)
void heap_init(heap *h, size_t value_size,
               int (*compare)(void const *a, void const *b));
void heap_free(heap *h);

size_t heap_size(heap const *h);
size_t heap_value_size(heap const *h);

// les trois fonctions suivantes sont indépendantes d'un tas en particulier
size_t heap_left_child(size_t i);
size_t heap_right_child(size_t i);
size_t heap_parent(size_t i);

void heap_send_up(heap *h, size_t i);
void heap_send_down(heap *h, size_t i);

// cette fonction peut être écrite en suivant la procédure décrite plus haut
void heap_insert(heap *h, void const *value);
// copie la valeur contenue dans la racine du tas à l'adresse pointée par value
void heap_max(heap const *h, void *value);
// cette fonction peut être écrite en suivant la procédure décrite plus haut
void heap_extract(heap *h, void *value);

void heap_build(heap *h);


#endif //P31_HEAP_H
