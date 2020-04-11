/* trie implementation, with arrays */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

#define ALPHABET_MIN 'a'
#define ALPHABET_MAX 'z'
#define ALPHABET_SIZE (ALPHABET_MAX - ALPHABET_MIN + 1)

#define MAX_WORD_SIZE 65

#define POS(c) ((c)-ALPHABET_MIN)    // character position in alphabet
#define CHAR(n) ((n) + ALPHABET_MIN) // n-th alphabet character

/* trie node */
typedef struct node
{
  struct node *child[ALPHABET_SIZE]; // children

  bool word;
  // end-of-word mark
} * Node;

/* trie */
typedef struct trie
{
  Node root;

} * Trie;

void node_print(Node node, char prefix[], char *word, int pos);

/*
  Allocates and returns a new trie node.
*/
static Node node_new(void)
{
  Node node = malloc(sizeof(*node));

  if (node != NULL)
  {
    node->word = false;

    for (int i = 0; i < ALPHABET_SIZE; ++i)
      node->child[i] = NULL;
  }

  return node;
}

/* Frees a trie NODE. */
static void node_free(Node node)
{
  free(node);
}

/* Destroys the sub-trie with root NODE. */
static void node_destroy(Node node)
{
  if (node == NULL)
    return;

  for (int i = 0; i < ALPHABET_SIZE; ++i)
    node_destroy(node->child[i]);

  node_free(node);
}

/*
  Creates and returns a new, empty trie.
*/
Trie trie_new(void)
{
  Trie trie = malloc(sizeof(struct trie));

  if (trie != NULL)
    trie->root = NULL;

  return trie;
}

/* Destroys trie T, freeing the memory it occupies. */
void trie_destroy(Trie t)
{
  node_destroy(t->root);

  free(t);
}

/* Checks whether trie T is empty. */
bool trie_empty(Trie t)
{
  return t->root == NULL;
}

/*
  Inserts word P into trie T.

  Returns true if the word was successfully inserted (or was already
  in the trie), false otherwise.
*/
bool trie_insert(Trie t, char p[])
{
  Node n;

  int i = 0;

  if (t->root == NULL)
    t->root = node_new(); // new, empty root node

  if (t->root == NULL)
    return false;

  n = t->root;

  // follow the word down the trie as long as possible,
  // taking care not to go to a nonexisting node
  while (p[i] != '\0' && n->child[POS(p[i])] != NULL)
  {
    n = n->child[POS(p[i])];
    i++;
  }

  // insert the new suffix into the trie
  while (p[i] != '\0')
  {
    n->child[POS(p[i])] = node_new();

    if (n->child[POS(p[i])] == NULL)
      return false;

    n = n->child[POS(p[i])];

    i++;
  }

  n->word = true;

  return true;
}

/*
   Searches for word P in trie T.

   Returns true if it finds it, false otherwise.
*/

bool trie_find(Trie t, char p[])
{
  if (t->root == NULL)
    return false;

  Node node = t->root;

  int i = 0;

  while (node != NULL && p[i] != '\0')
  {
    node = node->child[POS(p[i])];

    i++;
  }

  return node != NULL && node->word;
}

//count number of words
int node_count(Node node)
{
  int count = 0;

  if (node == NULL)
    return count;

  if (node->word)
    count++;

  for (int i = 0; i < ALPHABET_SIZE; i++)
    if (node->child[i] != NULL)
      count += node_count(node->child[i]);

  return count;
}

/* Counts and returns the number of words in trie T. */
int trie_count(Trie t)
{

  if (t == NULL)
    return 0;

  return node_count(t->root);
}

/* Prints all words in trie T with prefix P. */
void trie_print_completions(Trie t, char p[])
{

  if (t == NULL)
    return;

  int i = 0;

  Node node = t->root;

  while (node != NULL && p[i] != '\0')
  {
    node = node->child[POS(p[i])];

    i++;
  }

  char word[MAX_WORD_SIZE];

  if (node != NULL)
    node_print(node, p, word, 0);
}

//check the geven node is empty
bool node_is_empty(Node node)
{
  for (int i = 0; i < ALPHABET_SIZE; i++)
    if (node->child[i] != NULL)
      return false;

  return true;
}

//remove a node
void node_remove(Node current, char p[], int index, int len)
{
  if (current == NULL)
    return;

  if ((index + 1) == len)
  {
    current->word = false;
    return;
  }

  if (node_is_empty(current) && !current->word)
  {
    node_free(current);
    return;
  }

  node_remove(current->child[POS(p[index + 1])], p, index + 1, len);
}

/* Removes word P from trie T. */
void trie_delete(Trie t, char p[])
{

  if (t == NULL)
    return;

  int lenght = strlen(p);
  node_remove(t->root, p, -1, lenght);
}

//print  all nodes (words)
void node_print(Node node, char prefix[], char *word, int pos)
{
  if (node == NULL)
    return;

  if (node->word)
  {
    word[pos] = '\0';

    printf("%s%s\n", prefix, word);
  }

  for (int i = 0; i < ALPHABET_SIZE; i++)
  {
    if (node->child[i] != NULL)
    {
      word[pos] = CHAR(i);

      node_print(node->child[i], prefix, word, pos + 1);
    }
  }
}

/* Prints the full contents of trie T. */
void trie_print(Trie t)
{
  if (t == NULL)
    return;

  char word[47];

  node_print(t->root, "", word, 0);
}