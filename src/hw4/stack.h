#pragma once
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

// function removes value on top of the stack and returns it
bool pop(Stack* stack);

// function peek returns value on top of the stack without removing it
bool peek(Stack* stack);

// function of deleting the stack(freeing memory)
void deleteStack(Stack* stack);
