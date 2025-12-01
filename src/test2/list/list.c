#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

List *createList() {
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL) {
    return NULL;
  }
  list->head = NULL;
  list->size = 0;
  return list;
}

List *createListFromArray(int arr[], int size) {
  List *list = createList();
  if (list == NULL) {
    return NULL;
  }

  for (int i = size - 1; i >= 0; i--) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
      destroyList(list);
      return NULL;
    }
    newNode->value = arr[i];
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
  }

  return list;
}

void destroyList(List *list) {
  if (list == NULL) {
    return;
  }

  ListNode *current = list->head;
  while (current != NULL) {
    ListNode *next = current->next;
    free(current);
    current = next;
  }

  free(list);
}

List *copyList(const List *list) {
  if (list == NULL) {
    return NULL;
  }

  List *newList = createList();
  if (newList == NULL) {
    return NULL;
  }

  if (list->head == NULL) {
    return newList;
  }

  ListNode *current = list->head;
  ListNode *prevNew = NULL;

  while (current != NULL) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
      destroyList(newList);
      return NULL;
    }

    newNode->value = current->value;
    newNode->next = NULL;

    if (prevNew == NULL) {
      newList->head = newNode;
    } else {
      prevNew->next = newNode;
    }

    prevNew = newNode;
    newList->size++;
    current = current->next;
  }

  return newList;
}

List *reverseList(const List *list) {
  if (list == NULL) {
    return NULL;
  }

  List *reversed = createList();
  if (reversed == NULL) {
    return NULL;
  }

  ListNode *current = list->head;
  while (current != NULL) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
      destroyList(reversed);
      return NULL;
    }

    newNode->value = current->value;
    newNode->next = reversed->head;
    reversed->head = newNode;
    reversed->size++;

    current = current->next;
  }

  return reversed;
}

List *appendToList(const List *list, int value) {
  if (list == NULL) {
    return NULL;
  }

  List *newList = copyList(list);
  if (newList == NULL) {
    return NULL;
  }

  ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
  if (newNode == NULL) {
    destroyList(newList);
    return NULL;
  }

  newNode->value = value;
  newNode->next = NULL;

  if (newList->head == NULL) {
    newList->head = newNode;
  } else {
    ListNode *current = newList->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }

  newList->size++;
  return newList;
}

int listSize(const List *list) { return list == NULL ? 0 : list->size; }

bool isEmptyList(const List *list) {
  return list == NULL || list->head == NULL;
}

int getFirst(const List *list) {
  if (list == NULL || list->head == NULL) {
    return -1;
  }
  return list->head->value;
}

int getLast(const List *list) {
  if (list == NULL || list->head == NULL) {
    return -1;
  }

  ListNode *current = list->head;
  while (current->next != NULL) {
    current = current->next;
  }
  return current->value;
}

List *removeFirst(const List *list) {
  if (list == NULL || list->head == NULL) {
    return createList();
  }

  List *newList = createList();
  if (newList == NULL) {
    return NULL;
  }

  ListNode *current = list->head->next;
  while (current != NULL) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
      destroyList(newList);
      return NULL;
    }

    newNode->value = current->value;
    newNode->next = NULL;

    if (newList->head == NULL) {
      newList->head = newNode;
    } else {
      ListNode *last = newList->head;
      while (last->next != NULL) {
        last = last->next;
      }
      last->next = newNode;
    }

    newList->size++;
    current = current->next;
  }

  return newList;
}

void printList(const List *list) {
  if (list == NULL) {
    printf("NULL\n");
    return;
  }

  ListNode *current = list->head;
  printf("[");
  while (current != NULL) {
    printf("%d", current->value);
    if (current->next != NULL) {
      printf(", ");
    }
    current = current->next;
  }
  printf("]");
}

bool areListsEqual(const List *list1, const List *list2) {
  if (list1 == NULL || list2 == NULL) {
    return list1 == list2;
  }

  if (listSize(list1) != listSize(list2)) {
    return false;
  }

  ListNode *curr1 = list1->head;
  ListNode *curr2 = list2->head;

  while (curr1 != NULL && curr2 != NULL) {
    if (curr1->value != curr2->value) {
      return false;
    }
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  return curr1 == NULL && curr2 == NULL;
}