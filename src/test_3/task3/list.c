#include <stdlib.h>
#include "list.h"

Node *listPush(Node *head, int value)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
        return head;         
    n->value = value;
    n->next  = head;
    return n;
}

void listFree(Node *head)
{
    while (head) {
        Node *tmp = head->next;
        free(head);
        head = tmp;
    }
}


Node *listReverse(Node *head)
{
    Node *prev = NULL;
    Node *cur  = head;
    while (cur) {
        Node *next = cur->next;
        cur->next = prev;      
        prev = cur;
        cur  = next;
    }
    return prev;               
}
