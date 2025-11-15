#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
    return NULL;
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
  if (*head == NULL)
    return;

  Node *temp = *head;
  Node *prev = NULL;

  if (temp != NULL && temp->data == value) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->data != value) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;
  free(temp);
}

void freeList(Node *head) {
  Node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int getListSize(Node *head) {
  int size = 0;
  Node *current = head;
  while (current != NULL) {
    size++;
    current = current->next;
  }
  return size;
}

bool isListSorted(Node *head) {
  if (head == NULL || head->next == NULL)
    return true;

  Node *current = head;
  while (current->next != NULL) {
    if (current->data > current->next->data) {
      return false;
    }
    current = current->next;
  }
  return true;
}

static bool testEmptyList() {
  Node *head = NULL;
  bool result = (getListSize(head) == 0 && isListSorted(head));
  printf("emptyList: %s\n", result ? "PASS" : "FAIL");
  return result;
}

static bool testInsertSorted() {
  Node *head = NULL;
  insertSorted(&head, 3);
  insertSorted(&head, 1);
  insertSorted(&head, 2);
  bool result = (getListSize(head) == 3 && isListSorted(head));
  printf("insertSorted: %s\n", result ? "PASS" : "FAIL");
  freeList(head);
  return result;
}

static bool testDuplicates() {
  Node *head = NULL;
  insertSorted(&head, 2);
  insertSorted(&head, 2);
  insertSorted(&head, 1);
  bool result = (getListSize(head) == 3 && isListSorted(head));
  printf("duplicates: %s\n", result ? "PASS" : "FAIL");
  freeList(head);
  return result;
}

static bool testDeleteOperations() {
  Node *head = NULL;
  insertSorted(&head, 1);
  insertSorted(&head, 2);
  insertSorted(&head, 3);

  deleteValue(&head, 2);
  bool result1 = (getListSize(head) == 2 && isListSorted(head));

  deleteValue(&head, 5);
  bool result2 = (getListSize(head) == 2 && isListSorted(head));

  deleteValue(&head, 1);
  bool result3 = (getListSize(head) == 1 && isListSorted(head));

  bool result = result1 && result2 && result3;
  printf("deleteOperations: %s\n", result ? "PASS" : "FAIL");
  freeList(head);
  return result;
}

static bool testComplexScenario() {
  Node *head = NULL;

  insertSorted(&head, 5);
  insertSorted(&head, 1);
  insertSorted(&head, 3);
  insertSorted(&head, -2);

  deleteValue(&head, 3);
  insertSorted(&head, 4);
  deleteValue(&head, 1);

  bool result = (getListSize(head) == 3 && isListSorted(head));
  printf("complexScenario: %s\n", result ? "PASS" : "FAIL");
  freeList(head);
  return result;
}

void runAllTests() {
  printf("ТЕСТЫ СОРТИРОВАННОГО СПИСКА\n\n");

  bool results[] = {testEmptyList(), testInsertSorted(), testDuplicates(),
                    testDeleteOperations(), testComplexScenario()};

  int total = sizeof(results) / sizeof(results[0]);
  int passed = 0;

  for (int i = 0; i < total; i++) {
    if (results[i])
      passed++;
  }

  printf("\nИтог: %d/%d\n", passed, total);

  if (passed == total) {
    printf("ВСЕ ТЕСТЫ ПРОЙДЕНЫ\n");
  } else {
    printf("ЕСТЬ ОШИБКИ\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2 && strcmp(argv[1], "--test") == 0) {
    runAllTests();
    return 0;
  }

  printf("Для запуска тестов используйте: %s --test\n", argv[0]);
  return 0;
}