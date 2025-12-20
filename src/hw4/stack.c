#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

struct Stack newStack(void)
{
    struct Stack stack = { .head = NULL };
    return stack;
}

bool push(struct Stack* stack, int value)
{
    struct StackNode* node = malloc(sizeof(struct StackNode));
    if (node == NULL)
        return false;
    node->value = value;
    node->next = stack->head;
    stack->head = node;
    return true;
}

bool pop(struct Stack* stack, int* value)
{
    if (stack->head == NULL)
        return false;

    struct StackNode* oldNode = stack->head;
    *value = oldNode->value;
    stack->head = oldNode->next;
    free(oldNode);
    return true;
}

bool peek(struct Stack* stack, int* value)
{
    if (stack->head == NULL)
        return false;
    *value = stack->head->value;
    return true;
}

void deleteStack(struct Stack* stack)
{
    int temp = 0;
    while (stack->head != NULL) {
        pop(stack, &temp);
    }
}