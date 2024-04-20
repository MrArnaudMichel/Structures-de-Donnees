//
// Created by arnaud on 28/11/2023.
//

#ifndef P31_LINKED_LIST_H
#define P31_LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct linked_list_node{
    void *data;
    void *next;
} linked_list_node;

typedef struct linked_list{
    linked_list_node *head;
    size_t value_size;
} linked_list;

void ll_init(linked_list *ll, size_t value_size);
// il est probablement plus prudent d'écrire cette fonction après avoir écrit
// les fonctions de manipulation des données
void ll_free(linked_list *ll);

size_t ll_size(linked_list const *ll);
size_t ll_value_size(linked_list const *ll);

// retourne un pointeur sur le noeud d'index index
linked_list_node const *ll_get_node(linked_list const *ll, size_t index);
// copie la mémoire pointée par value dans les données du noeud n
void ll_set_node_value(linked_list const *ll, linked_list_node *n, void const *value);
// copie la mémoire pointée par value dans un nouveau noeud à la fin de la liste ll,
// puis retourne un pointeur sur ce noeud
linked_list_node *ll_push_back(linked_list *ll, void const *value);
// copie la mémoire pointée par value dans un nouveau noeud au début de la liste ll,
// puis retourne un pointeur sur ce noeud
linked_list_node *ll_push_front(linked_list *ll, void const *value);
// copie la mémoire pointée par value dans un nouveau noeud inséré après le noeud n
// dans la liste ll, puis retourne un pointeur sur ce noeud
linked_list_node *ll_insert_after_node(linked_list *ll, linked_list_node *n,
                                       void const *value);
// copie la mémoire pointée par value dans un nouveau noeud inséré avant le noeud n
// dans la liste ll, puis retourne un pointeur sur ce noeud
linked_list_node *ll_insert_before_node(linked_list *ll, linked_list_node *n,
                                        void const *value);
// supprime le noeud n de la liste ll
void ll_erase_node(linked_list *ll, linked_list_node *n);

linked_list_node const *find(linked_list const *ll, void const *value, bool (*equals)(void const *a, void const *b));

#endif //P31_LINKED_LIST_H
