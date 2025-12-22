#pragma once

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// for errors
typedef enum { ok = 0,
    error_memory,
    error_not_found,
    error_empty } ErrorCode;

// function for list
Node* createNode(int value, ErrorCode* error);
ErrorCode insertSorted(Node** head, int value);
ErrorCode deleteValue(Node** head, int value);
void printList(Node* head);
void freeList(Node* head);