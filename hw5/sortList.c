#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int value, ErrorCode* error)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        if (error != NULL) {
            *error = error_memory;
        }
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

ErrorCode insertSorted(Node** head, int value)
{
    ErrorCode error;
    Node* newNode = createNode(value, &error);
    if (newNode == NULL)
        return error_memory;

    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return ok;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return ok;
}

ErrorCode deleteValue(Node** head, int value)
{
    if (*head == NULL) {
        return error_empty;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return error_not_found;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    return ok;
}

void printList(Node* head)
{
    if (head == NULL) {
        printf("Список пуст!\n");
        return;
    }

    printf("Текущий список: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(Node* head)
{
    Node* temp = NULL;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}