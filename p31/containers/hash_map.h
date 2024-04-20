//
// Created by arnaud on 19/12/2023.
//

#ifndef P31_HASH_MAP_H
#define P31_HASH_MAP_H

#include <stdbool.h>
#include <stddef.h>
#include "linked_list.h"

typedef struct hash_map {
    vector *buckets;
    size_t value_size;
} hash_map;

typedef struct key_value_pair {
    char *key;
    void *value;
} key_value_pair;

// initialise un vector de taille nb_buckets dont chaque case contient
// une liste chaînée de key_value_pair
void hash_map_init(hash_map *hm, size_t nb_buckets, size_t value_size);
// il est probablement plus prudent d'écrire cette fonction après avoir écrit
// les fonctions de manipulation des données
void hash_map_free(hash_map *h);

size_t hash_map_size(hash_map const *h);
size_t hash_map_value_size(hash_map const *h);


// retourne vrai si la clé key est présente dans la table de hachage h, faux sinon
bool hash_map_contains(hash_map const *h, char const *key);
// après avoir vérifié que la clé key n'est pas déjà présente dans la table de
// hachage h, copie les clé et valeur dans un nouveau key_value_pair et insère
// ce dernier en tête de la liste chaînée correspondant à la clé
void hash_map_insert(hash_map *h, char const *key, void const *value);
// copie la valeur contenue dans la key_value_pair correspondant à la clé key
// à l'adresse pointée par value
// (suppose que la clé key est présente dans la table de hachage h)
void hash_map_get(hash_map const *h, char const *key, void *value);
// copie la mémoire pointée par value dans la key_value_pair correspondant à la clé key
// (suppose que la clé key est présente dans la table de hachage h)
void hash_map_set(hash_map *h, char const *key, void const *value);
// supprime la key_value_pair correspondant à la clé key
// (suppose que la clé key est présente dans la table de hachage h)
void hash_map_erase(hash_map *h, char const *key);

void hash_map_foreach(hash_map const *h,
                      void (*f)(char const *key, void const *value));

// La hash_map h contient des données de type int
void text_analysis(char const *filename, hash_map *h);

#endif //P31_HASH_MAP_H
