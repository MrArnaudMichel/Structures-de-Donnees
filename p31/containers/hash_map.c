//
// Created by arnaud on 19/12/2023.
//
#include "utils.h"
#include "vector.h"
#include "hash_map.h"

#include <stdio.h>


// initialise un vector de taille nb_buckets dont chaque case contient
// une liste chaînée de key_value_pair
void hash_map_init(hash_map *hm, size_t nb_buckets, size_t value_size) {
    hm->buckets = malloc(sizeof(vector));
    vec_init( hm->buckets, sizeof(linked_list));
    hm->value_size = value_size;
    vec_reserve(hm->buckets, nb_buckets);
    for (size_t i = 0; i < nb_buckets; ++i) {
        linked_list *l = (linked_list*)vec_get_pointer(hm->buckets, i);
        ll_init(l, sizeof(key_value_pair));
    }
    hm->buckets->size = nb_buckets;
}
// il est probablement plus prudent d'écrire cette fonction après avoir écrit
// les fonctions de manipulation des données
void hash_map_free(hash_map *h){
    for (size_t i = 0; i < h->buckets->capacity; i++) {
        linked_list *l = (linked_list*)vec_get_pointer(h->buckets, i);
        for (size_t j = 0; j < ll_size(l); ++j) {
            key_value_pair *p = ll_get_node(l, j)->data;
            free(p->key);
            free(p->value);
        }
        ll_free(l);
    }
    vec_free(h->buckets);
}

size_t hash_map_size(hash_map const *h){
    return h->buckets->size;
}
size_t hash_map_value_size(hash_map const *h){
    return h->value_size;
}


bool hash_map_contains(hash_map const *h, char const *key){
    size_t bucket = str_hash(key) % h->buckets->size;
    linked_list *l = (linked_list*)vec_get_pointer(h->buckets, bucket);
    for (size_t i = 0; i < ll_size(l); ++i) {
        key_value_pair *p = ll_get_node(l, i)->data;
        if (strcmp(p->key, key) == 0) {
            return true;
        }
    }
    return false;
}

void hash_map_insert(hash_map *h, char const *key, void const *value){
    size_t bucket = str_hash(key) % h->buckets->size;
    linked_list *l = (linked_list*)vec_get_pointer(h->buckets, bucket);

    key_value_pair p;
    p.key = strdup(key);
    p.value = malloc(h->value_size);
    memcpy(p.value, value, h->value_size);

    ll_push_front(l, &p);
}


void hash_map_get(hash_map const *h, char const *key, void *value){
    size_t bucket = str_hash(key) % h->buckets->capacity;
    linked_list *l = (linked_list*)vec_get_pointer((vector *) h, bucket);
    for (size_t i = 0; i < ll_size(l); ++i) {
        key_value_pair *p = (key_value_pair*)ll_get_node(l, i);
        if (strcmp(p->key, key) == 0) {
            memcpy(value, p->value, h->value_size);
            return;
        }
    }
}
void hash_map_set(hash_map *h, char const *key, void const *value){
    size_t bucket = str_hash(key) % h->buckets->capacity;
    linked_list *l = (linked_list*)vec_get_pointer((vector *) h, bucket);
    for (size_t i = 0; i < ll_size(l); ++i) {
        key_value_pair *p = (key_value_pair*)ll_get_node(l, i);
        if (strcmp(p->key, key) == 0) {
            memcpy(p->value, value, h->value_size);
            return;
        }
    }
}
// supprime la key_value_pair correspondant à la clé key
// (suppose que la clé key est présente dans la table de hachage h)
void hash_map_erase(hash_map *h, char const *key){
    size_t bucket = str_hash(key) % h->buckets->capacity;
    linked_list *l = (linked_list*)vec_get_pointer((vector *) h, bucket);
    for (size_t i = 0; i < ll_size(l); ++i) {
        key_value_pair *p = (key_value_pair*)ll_get_node(l, i);
        if (strcmp(p->key, key) == 0) {
            ll_erase_node(l, ll_get_node(l, i));
            return;
        }
    }
}

void hash_map_foreach(hash_map const *h,
                      void (*f)(char const *key, void const *value)){
    for (size_t i = 0; i < h->buckets->capacity; ++i) {
        linked_list *l = (linked_list*)vec_get_pointer((vector *) h, i);
        for (size_t j = 0; j < ll_size(l); ++j) {
            key_value_pair *p = ll_get_node(l, j)->data;
            f(p->key, p->value);
        }
    }
}
