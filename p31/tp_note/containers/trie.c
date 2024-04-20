#include "trie.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// initialise un trie vide
void trie_init(trie *t)
{
    vec_init(&t->root.children, sizeof(trie_node *));
    vec_reserve(&t->root.children, 26);
    t->root.is_word = false;
}

// libère la mémoire occupée par le trie (tous les noeuds)
// on pourra faire appel à trie_free_node (défini ci-dessous)
void trie_free(trie *t)
{
    for (int i = 0; i < vec_size(&t->root.children); i++)
    {
        trie_free_node(*(trie_node **)vec_get_pointer(&t->root.children, i));
    }
    free(t);
}

// crée et retourne un nouveau noeud
// dans son état initial, ce nouveau noeud
// ne représente pas un mot et tous ses fils sont initialisés à NULL
trie_node *trie_create_node(void)
{
    trie_node *n = malloc(sizeof(trie_node));
    vec_init(&n->children, sizeof(trie_node *));
    vec_reserve(&n->children, 26);
    n->is_word = false;
    return n;
}

// libère le noeud donné ainsi que tout son sous-arbre (récursivement)
void trie_free_node(trie_node *n)
{
    for (int i = 0; i < vec_size(&n->children); i++)
    {
        trie_free_node(*(trie_node **)vec_get_pointer(&n->children, i));
    }
    vec_free(&n->children);
    free(n);
}

// insère le mot donné dans le trie
// les noeuds nécessaires à la représentation du mot sont créés si besoin
void trie_insert(trie *t, char const *word)
{
    trie_node *n = &t->root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i];
        int index = c - 'a';
        if (vec_size(&n->children) == 0)
        {
            vec_push_back(&n->children, &n);
        }
        trie_node *child = (trie_node *)vec_get_pointer(&n->children, index);
        if (child == NULL)
        {
            child = trie_create_node();
            vec_set_value(&n->children, index, &child);
        }
        printf("1");
        n = child;
    }
    n->is_word = true;
}

// indique si le trie contient le mot donné
bool trie_contains(trie const *t, char const *word)
{
    trie_node *n = (trie_node *)&t->root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i];
        int index = c - 'a';
        if (vec_size(&n->children) == 0)
        {
            return false;
        }
        trie_node *child = *(trie_node **)vec_get_pointer(&n->children, index);
        if (child == NULL)
        {
            return false;
        }
        n = child;
    }
    return n->is_word;
}

// écrit dans le buffer donné le premier mot dans l'ordre alphabétique
// contenu dans le trie et commençant par le préfixe donné
// (le buffer est supposé assez grand pour contenir le mot)
// - si aucun mot du trie ne commence par le préfixe donné, le buffer devra contenir une chaîne vide
// - si le préfixe correspond exactement à un mot du trie, le buffer devra contenir ce mot
void trie_first_word(trie const *t, char const *prefix, char *buffer)
{
    trie_node *n = (trie_node *)&t->root;
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        char c = prefix[i];
        int index = c - 'a';
        if (vec_size(&n->children) == 0)
        {
            return;
        }
        trie_node *child = (trie_node *)vec_get_pointer(&n->children, index);
        if (child == NULL)
        {
            return;
        }
        n = child;
    }
    if (n->is_word)

    {
        strcpy(buffer, prefix);
        return;
    }
    for (int i = 0; i < vec_size(&n->children); i++)
    {
        trie_node *child = (trie_node *)vec_get_pointer(&n->children, i);
        if (child != NULL)
        {
            char c = 'a' + i;
            char *new_prefix = malloc(strlen(prefix) + 2);
            strcpy(new_prefix, prefix);
            new_prefix[strlen(prefix)] = c;
            new_prefix[strlen(prefix) + 1] = '\0';
            trie_first_word(t, new_prefix, buffer);
            free(new_prefix);
            return;
        }
    }
}
