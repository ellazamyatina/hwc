#include <stdio.h>
#include "list.h"

void printList(Node *head)
{
    for (Node *p = head; p; p = p->next)
        printf("%d ", p->value);
    printf("\n");
}

int main(void)
{
    Node *head = NULL;

    head = listPush(head, 1);
    head = listPush(head, 2);
    head = listPush(head, 3);

    printf("Исходный список: ");
    printList(head);

    head = listReverse(head);

    printf("Перевёрнутый список: ");
    printList(head);

    listFree(head);
    return 0;
}
