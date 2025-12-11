#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *listPush(Node *head, int value);  
void  listFree(Node *head);                   
Node *listReverse(Node *head);                

#endif
