#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

Stack newStack(void)
{
    Stack stack = { .head = NULL };
    return stack;
}

bool push(Stack* stack, int value)
{
    StackNode* node = malloc(sizeof(StackNode));
    if (node == NULL)
        return false;
    node->value = value;
    node->next = stack->head;
    stack->head = node;
    return true;
}

bool pop(Stack* stack, int* value)
{
    if (stack->head == NULL)
        return false;

    StackNode* oldNode = stack->head;
    *value = oldNode->value;
    stack->head = oldNode->next;
    free(oldNode);
    return true;
}

bool peek(Stack* stack, int* value)
{
    if (stack->head == NULL)
        return false;
    *value = stack->head->value;
    return true;
}

void deleteStack(Stack* stack)
{
    int temp = 0;
    while (stack->head != NULL) {
        pop(stack, &temp);
    }
}