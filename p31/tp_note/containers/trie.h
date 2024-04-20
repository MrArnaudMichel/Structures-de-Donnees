#pragma once

#include <stdbool.h>
#include "vector.h"


typedef struct trie_node
{
  vector children;
  bool is_word;
} trie_node;

typedef struct trie
{
  trie_node root;
} trie;

void trie_init(trie *t);
void trie_free(trie *t);

trie_node *trie_create_node(void);
void trie_free_node(trie_node *n);

void trie_insert(trie *t, char const *word);
bool trie_contains(trie const *t, char const *word);

void trie_first_word(trie const *t, char const *prefix, char *buffer);
