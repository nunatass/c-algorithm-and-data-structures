
#include <stdbool.h>

#ifndef STACK_H

typedef struct stack *Stack;

Stack new_stack(int max_size);

Stack stack_resize(Stack stack, int new_max_size); //resize the stack capacity

void stack_push(Stack stack, int value); // insert data into stack

int stack_size(Stack stack); // get the stack size

bool stack_is_empty(Stack stack); //check if stack is empty

int stack_top(Stack stack); // get the last stack element

int stack_pop(Stack stack); // remove the last stack element

void stack_print(Stack stack); // print all stack elements

void stack_free(Stack stack); // free stack memory

#endif