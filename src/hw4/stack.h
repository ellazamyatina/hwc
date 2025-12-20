#pragma once
#include <stdbool.h>
// structure of simple elem in stack
typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

// create stack
typedef struct Stack {
    struct StackNode* head;
} Stack;

// function of creating new stack
Stack newStack(void);

// function adding new elem in the stack
bool push(Stack* stack, int value);

// function returs true if we can pop, else false, result of operation located
// in the pointer
bool pop(Stack* stack, int* value);

// function returns true if we can peek, else false, result of operation located
// in the pointer
bool peek(Stack* stack, int* value);

// function of deleting the stack(freeing memory)
void deleteStack(Stack* stack);
