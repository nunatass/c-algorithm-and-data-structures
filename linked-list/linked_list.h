#include <stdbool.h>

#ifndef LIST_EDA2
#define LIST_EDA2

typedef struct list linked_list;

linked_list *list_new(); //create a new list

int list_length(linked_list *lista);

bool list_empty(linked_list *lista); // free the list memory

bool list_insert(linked_list *lista, int value); //insert at the start of the list

bool list_insert_end(linked_list *lista, int value); //insert at the end of the list

bool list_insert_at_position(linked_list *lista, int value, int position);

//TODO: later change name to list_get_at_position
int list_nth(linked_list *lista, int n); // get the value at the position n

bool list_remove(linked_list *lista, int value); // remove the fst occurrence of the value

int list_remove_at_position(linked_list *lista, int position);

int list_find(linked_list *lista, int value); //find the fst occurrence of the value

void list_replace_at(linked_list *lista, int value, int position);

void list_print(linked_list *lista);

void list_destroy(linked_list *lista); // free the list memory

//extra extra
linked_list *sort(linked_list *lista);

#endif