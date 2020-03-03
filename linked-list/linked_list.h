#include <stdbool.h>

#ifndef LIST_EDA2
#define LIST_EDA2

typedef struct list linked_list;

linked_list *list_new(); //create a new list

int list_length(linked_list *list);

bool list_empty(linked_list *list); // free the list memory

bool list_insert(linked_list *list, int value); //insert at the start of the list

bool list_insert_end(linked_list *list, int value); //insert at the end of the list

bool list_insert_at_position(linked_list *list, int value, int position);

int list_get_at_position(linked_list *list, int n); // get the value at the position n

bool list_remove(linked_list *list, int value); // remove the fst occurrence of the value

int list_remove_at_position(linked_list *list, int position);

int list_find(linked_list *list, int value); //find the fst occurrence of the value

void list_replace_at(linked_list *list, int value, int position);

void list_print(linked_list *list);

void list_destroy(linked_list *list); // free the list memory

#endif