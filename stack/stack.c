#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//#define MAX_SIZE 1000
#define INT_MIN -2147483648

typedef struct stack
{
    int *arr;
    int max_size;
    int top;

} * Stack;

//stack initialization
Stack new_stack(int max_size)
{
    Stack new_stack = malloc(sizeof(Stack));

    new_stack->arr = malloc(max_size * sizeof(int));

    new_stack->max_size = max_size;

    if (new_stack == NULL)
        return NULL;

    new_stack->top = -1;

    return new_stack;
}

//resize the stack capacity
Stack stack_resize(Stack stack, int new_max_size)
{

    Stack new_stack = realloc(stack, new_max_size);

    if (new_stack != NULL)
        return new_stack;

    printf("Error resizing stack\n");

    return stack;
}

//insertion in top of the stack
void stack_push(Stack stack, int value)
{
    stack->top++;

    stack->arr[stack->top] = value;
}

// get the size of the stack
int stack_size(Stack stack)
{
    return stack->top + 1;
}

bool stack_is_empty(Stack stack)
{
    return stack->top == -1;
}

// remove the element in top of the stack
int stack_top(Stack stack)
{
    if (stack_is_empty(stack))
        return INT_MIN;

    return stack->arr[stack->top];
}

//get the element in top of the stack
int stack_pop(Stack stack)
{
    if (stack_is_empty(stack))
        return INT_MIN;

    int tmp = stack->arr[stack->top];

    stack->top--;

    return tmp;
}

// fre all stack memory
void stack_free(Stack stack)
{
    for (int i = stack->max_size - 1; i <= 0; i--)
        free(stack->arr[i]);

    free(stack);
}

//print all elements in the stack
void stack_print(Stack stack)
{
    printf("[");

    for (int i = 0; i < stack_size(stack); i++)
    {
        printf(" %d", stack->arr[i]);
    }
    printf(" ]\n");
}
