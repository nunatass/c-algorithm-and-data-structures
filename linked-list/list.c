#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//linked-list node
typedef struct node
{
    int data;

    struct node *next;

    struct node *previous;

} node;

//linked-list list
typedef struct list
{
    node *head;

    node *tail;

    int length;

} list;

//node initialization
node *node_new(node *previous, node *next, int value)
{
    node *new_node = malloc(sizeof(node));

    if (new_node == NULL)
        return NULL;

    new_node->previous = previous;

    new_node->next = next;

    new_node->data = value;

    return new_node;
}

//linked_list initialization
list *list_new()
{
    list *new_list = malloc(sizeof(list));

    if (new_list == NULL)
        return NULL;

    new_list->head = node_new(NULL, NULL, 0);

    new_list->tail = new_list->head;

    new_list->length = 0;

    return new_list;
}

//list size
int list_length(list *lista)
{
    return lista->length;
}

bool list_empty(list *lista)
{
    return lista->length == 0;
}

//insertion at the start of the list
bool list_insert(list *lista, int value)
{
    node *new_node = node_new(lista->head, lista->head->next, value);

    if (new_node == NULL)
        return false;

    if (new_node->next != NULL)
        new_node->next->previous = new_node;

    //set the new node as the head next node
    lista->head->next = new_node;

    lista->length++;

    //checking if it is the first insertion, so set the tail as this node
    if (lista->head == lista->tail)
        lista->tail = new_node;

    return true;
}

//insertion at the and of the list
bool list_insert_end(list *lista, int value)
{
    node *new_node = node_new(lista->tail, NULL, value);

    if (new_node == NULL)
        return false;

    //linking the last tail to the new node
    lista->tail->next = new_node;

    //set the new tail as the new node
    lista->tail = new_node;

    lista->length++;

    return true;
}

bool list_insert_at_position(list *lista, int value, int position)
{
    //check if position isn't out of the range
    if (position < 0 || position > lista->length)
        return false;

    node *current = lista->head;

    for (int index = 0; index < position; index++)
        current = current->next;

    node *new_node = node_new(current, current->next, value);

    if (new_node == NULL)
        return false;

    //linking the previous node to the new node
    current->next = new_node;

    lista->length++;

    return true;
}

//TODO: later, change this name to list_get_at_position
/// get the value at the position n
int list_nth(list *lista, int position)
{
    node *current = lista->head;

    for (int index = 0; index < position; index++)
        current = current->next;

    return current->next->data;
}

// remove the fst occurrence of the value
bool list_remove(list *lista, int value)
{
    node *current = lista->head->next;

    while (current != NULL)
    {
        if (current->data == value)
        {
            //linking the previous of current node, to the next of current node
            current->previous->next = current->next;

            if (current->next != NULL)
                current->next->previous = current->previous;

            free(current);

            return true;
        }

        current = current->next;
    }

    return false;
}

int list_remove_at_position(list *lista, int position)
{
    node *current = lista->head->next;

    for (int i = 0; i < position; i++)
        current = current->next;

    current->previous->next = current->next;

    if (current->next != NULL)
        current->next->previous = current->previous;

    int removed_value = current->data;

    free(current);

    lista->length--;

    return removed_value;
}

//find the fst occurrence of the value
int list_find(list *lista, int value)
{
    node *current = lista->head;

    for (int i = 0; current->next != NULL; i++)
    {
        current = current->next;

        if (current->data == value)
            return i;
    }

    return -1;
}

//replace the current value at the given position to a new value
void list_replace_at(list *lista, int value, int position)
{
    node *current = lista->head;

    for (int i = 0; i < position; i++)
        current = current->next;

    current->next->data = value;
}

//print the list values [l1 l2 ...]
void list_print(list *lista)
{
    node *current = lista->head->next;

    printf("[");

    while (current != NULL)
    {
        printf("%d ", current->data);

        current = current->next;
    }

    printf("]\n");
}

// free all memory used in the list
void list_destroy(list *lista)
{

    node *current = lista->head;

    node *next = current->next;

    while (next != NULL)
    {
        free(current);

        current = next;

        next = next->next;
    };

    lista->length;
}
