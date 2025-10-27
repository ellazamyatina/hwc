#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *addValue(Node *head, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;

  if (head == NULL || value < head->data) {
    newNode->next = head;
    return newNode;
  }

  Node *current = head;
  while (current->next != NULL && current->next->data < value) {
    current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;
  return head;
}

Node *removeValue(Node *head, int value) {
  if (head == NULL)
    return NULL;

  if (head->data == value) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  Node *current = head;
  while (current->next != NULL && current->next->data != value) {
    current = current->next;
  }

  if (current->next != NULL) {
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
  }

  return head;
}

void printList(Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  int choice, value;

  printf("0-выход 1-добавить 2-удалить 3-печать\n");

  while (1) {
    printf("> ");
    scanf("%d", &choice);

    if (choice == 0)
      break;

    switch (choice) {
    case 1:
      scanf("%d", &value);
      head = addValue(head, value);
      break;
    case 2:
      scanf("%d", &value);
      head = removeValue(head, value);
      break;
    case 3:
      printList(head);
      break;
    }
  }

  return 0;
}