#pragma once
// structure of simple elem in stack
struct StackNode {
  int value;
  struct StackNode *next;
};

// create stack
struct Stack {
  struct StackNode *head;
};

// function of creating new stack
struct Stack newStack(void);

// function adding new elem in the stack
void push(struct Stack *stack, int value);

// function bring elem from the stack
int pop(struct Stack *stack);

// function "peek" accepts pointer on the last elem of the stack
int peek(struct Stack *stack);

// function of deleting the stack(freeing memory)
void deleteStack(struct Stack *stack);
