/* trie interface */

#include <stdbool.h>

typedef struct trie *Trie;

Trie trie_new(void);

void trie_destroy(Trie);

bool trie_empty(Trie);

bool trie_find(Trie, char[]);

bool trie_insert(Trie, char[]);

void trie_delete(Trie, char[]);

int trie_count(Trie);

void trie_print(Trie);

void trie_print_completions(Trie, char[]);