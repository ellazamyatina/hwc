#ifndef SORT_LIST_H
#define SORT_LIST_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

// function for list
Node *createNode(int value);
void insertSorted(Node **head, int value);

void deleteValue(Node **head, int value);
void printList(Node *head);
void freeList(Node *head);

#endif