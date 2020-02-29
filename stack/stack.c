#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//#define MAX_SIZE 1000
#define INT_MIN -2147483647

typedef struct stack
{
    int *arr;
    int max_size;
    int top;

} stack;

//stack initialization
stack *new_stack(int max_size)
{
    stack *new_stack = malloc(sizeof(stack));

    new_stack->arr = malloc(max_size * sizeof(int));

    new_stack->max_size = max_size;

    if (new_stack == NULL)
        return NULL;

    new_stack->top = -1;

    return new_stack;
}

//insertion in top of the stack
void stack_push(stack *stack, int value)
{
    stack->top++;

    stack->arr[stack->top] = value;
}

// get the size of the stack
int stack_size(stack *stack)
{
    return stack->top + 1;
}

bool stack_is_empty(stack *stack)
{
    return stack->top == -1;
}

// remove the element in top of the stack
int stack_top(stack *stack)
{
    if (stack_is_empty(stack))
        return INT_MIN;

    return stack->arr[stack->top];
}

//get the element in top of the stack
int stack_pop(stack *stack)
{
    if (stack_is_empty(stack))
        return INT_MIN;

    int tmp = stack->arr[stack->top];

    stack->top--;

    return tmp;
}

// fre all stack memory
void stack_free(stack *stack)
{
    for (int i = stack->max_size - 1; i <= 0; i--)
        free(stack->arr[i]);

    free(stack);
}

//print all elements in the stack
void stack_print(stack *stack)
{
    printf("[");

    for (int i = 0; i < stack_size(stack); i++)
    {
        printf(" %d", stack->arr[i]);
    }
    printf(" ]\n");
}
