#include "stack.h"
#include <stdlib.h>

struct Stack newStack(void) {
  struct Stack stack = {.head = NULL};
  return stack;
}

void push(struct Stack *stack, int value) {
  struct StackNode *node = malloc(sizeof(struct StackNode));
  node->value = value;
  node->next = stack->head;
  stack->head = node;
}

int pop(struct Stack *stack) {
  if (stack->head == NULL) {
    return -1;
  }
  struct StackNode *oldNode = stack->head;
  int res = oldNode->value;
  stack->head = oldNode->next;
  free(oldNode);
  return res;
}

int peek(struct Stack *stack) {
  if (stack->head == NULL) {
    return -1;
  }
  return stack->head->value;
}

void deleteStack(struct Stack *stack) {
  while (stack->head != NULL) {
    pop(stack);
  }
}