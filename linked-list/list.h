#include <stdbool.h>

#ifndef LIST_EDA2
#define LIST_EDA2

typedef struct list list;

list *list_new(); //create a new list

int list_length(list *lista);

bool list_empty(list *lista); // free the list memory

bool list_insert(list *lista, int value); //insert at the start of the list

bool list_insert_end(list *lista, int value); //insert at the end of the list

bool list_insert_at_position(list *lista, int value, int position);

//TODO: later change name to list_get_at_position
int list_nth(list *lista, int n); // get the value at the position n

bool list_remove(list *lista, int value); // remove the fst occurrence of the value

int list_remove_at_position(list *lista, int position);

int list_find(list *lista, int value); //find the fst occurrence of the value

void list_replace_at(list *lista, int value, int position);

void list_print(list *lista);

void list_destroy(list *lista); // free the list memory

//extra extra
list *sort(list *lista);

#endif