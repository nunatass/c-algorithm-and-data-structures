#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//linked-list node
typedef struct node
{
    int data;

    struct node *next;

    struct node *previous;

} * node;

//linked-list list
typedef struct list
{
    node head;

    node tail;

    int length;

} * linked_list;

//node initialization
node node_new(node previous, node next, int value)
{
    node new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
        return NULL;

    new_node->previous = previous;

    new_node->next = next;

    new_node->data = value;

    return new_node;
}

//linked_list initialization
linked_list list_new()
{
    linked_list new_list = malloc(sizeof(struct list));

    if (new_list == NULL)
        return NULL;

    new_list->head = node_new(NULL, NULL, 0);

    new_list->tail = new_list->head;

    new_list->length = 0;

    return new_list;
}

//list size
int list_length(linked_list list)
{
    return list->length;
}

bool list_empty(linked_list list)
{
    return list->length == 0;
}

//insertion at the start of the list
bool list_insert(linked_list list, int value)
{
    node new_node = node_new(list->head, list->head->next, value);

    if (new_node == NULL)
        return false;

    if (new_node->next != NULL)
        new_node->next->previous = new_node;

    //set the new node as the head next node
    list->head->next = new_node;

    list->length++;

    //checking if it is the first insertion, so set the tail as this node
    if (list->head == list->tail)
        list->tail = new_node;

    return true;
}

//insertion at the and of the list
bool list_insert_end(linked_list list, int value)
{
    node new_node = node_new(list->tail, NULL, value);

    if (new_node == NULL)
        return false;

    //linking the last tail to the new node
    list->tail->next = new_node;

    //set the new tail as the new node
    list->tail = new_node;

    list->length++;

    return true;
}

bool list_insert_at_position(linked_list list, int value, int position)
{
    //check if position isn't out of the range
    if (position < 0 || position > list->length)
        return false;

    node current = list->head;

    for (int index = 0; index < position; index++)
        current = current->next;

    node new_node = node_new(current, current->next, value);

    if (new_node == NULL)
        return false;

    //linking the previous node to the new node
    current->next = new_node;

    list->length++;

    return true;
}

/// get the value at the position n
node list_get_node_at_position(linked_list list, int position)
{
    node current = list->head;

    for (int index = 0; index < position; index++)
        current = current->next;

    return current->next;
}

//TODO: later, change this name to list_get_at_position
/// get the value at the position n
int list_get_at_position(linked_list list, int position)
{
    return list_get_node_at_position(list, position)->data;
}

// remove the fst occurrence of the value
bool list_remove(linked_list list, int value)
{
    node current = list->head->next;

    while (current != NULL)
    {
        if (current->data == value)
        {
            //linking the previous of current node, to the next of current node
            current->previous->next = current->next;

            // linking current next previous with current previous node
            if (current->next != NULL)
                current->next->previous = current->previous;
            else
                list->tail = current->previous; // set tail to curret previous  node

            free(current);

            list->length--;

            return true;
        }

        current = current->next;
    }

    return false;
}

int list_remove_at_position(linked_list list, int position)
{
    node current = list->head->next;

    for (int i = 0; i < position; i++)
        current = current->next;

    // linking current previous next to  current next ndoe
    current->previous->next = current->next;

    // linking current next previous with current previeus node
    if (current->next != NULL)
        current->next->previous = current->previous;

    else
        list->tail = current->previous; // set tail to curret previous  node

    int removed_value = current->data;

    free(current);

    list->length--;

    return removed_value;
}

//find the fst occurrence of the value
int list_find(linked_list list, int value)
{
    node current = list->head;

    for (int i = 0; current->next != NULL; i++)
    {
        current = current->next;

        if (current->data == value)
            return i;
    }

    return -1;
}

//replace the current value at the given position to a new value
void list_replace_at(linked_list list, int value, int position)
{
    node current = list->head;

    for (int i = 0; i < position; i++)
        current = current->next;

    current->next->data = value;
}

//print the list values [l1 l2 ...]
void list_print(linked_list list)
{
    node current = list->head->next;

    printf("[");

    while (current != NULL)
    {
        printf("%d ", current->data);

        current = current->next;
    }

    printf("]\n");
}

// free all memory used in the list
void list_destroy(linked_list list)
{

    node current = list->head;

    node next = current->next;

    while (next != NULL)
    {
        free(current);

        current = next;

        next = next->next;
    };

    free(list);
}
