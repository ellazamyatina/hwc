#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Ошибка выделения памяти!\n");
    return NULL;
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

void insertSorted(Node **head, int value) {
  Node *newNode = createNode(value);
  if (newNode == NULL)
    return;

  if (*head == NULL || value < (*head)->data) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  Node *current = *head;
  while (current->next != NULL && current->next->data < value) {
    current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;
}

void deleteValue(Node **head, int value) {
  if (*head == NULL) {
    printf("Список пуст!\n");
    return;
  }

  Node *temp = *head;
  Node *prev = NULL;

  if (temp != NULL && temp->data == value) {
    *head = temp->next;
    free(temp);
    printf("Значение %d удалено из списка.\n", value);
    return;
  }

  while (temp != NULL && temp->data != value) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Значение %d не найдено в списке!\n", value);
    return;
  }

  prev->next = temp->next;
  free(temp);
  printf("Значение %d удалено из списка.\n", value);
}

void printList(Node *head) {
  if (head == NULL) {
    printf("Список пуст!\n");
    return;
  }

  printf("Текущий список: ");
  Node *current = head;
  while (current != NULL) {
    printf("%d", current->data);
    if (current->next != NULL) {
      printf(" -> ");
    }
    current = current->next;
  }
  printf("\n");
}

void freeList(Node *head) {
  Node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}