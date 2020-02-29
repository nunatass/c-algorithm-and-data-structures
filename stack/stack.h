
#include <stdbool.h>

#ifndef STACK_H

typedef struct stack *stack;

stack new_stack();

void stack_push(stack stack, int value); // insert data into stack

int stack_size(stack stack); // get the stack size

bool stack_is_empty(stack stack); //check if stack is empty

int stack_top(stack stack); // get the last stack element

int stack_pop(stack stack); // remove the last stack element

void stack_print(stack stack); // print all stack elements

void stack_free(stack stack); // free stack memory

#endif