#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

typedef struct {
  ListNode *head;
  int size;
} List;

List *createList();
List *createListFromArray(int arr[], int size);
void destroyList(List *list);
List *copyList(const List *list);
List *reverseList(const List *list);
List *appendToList(const List *list, int value);
int listSize(const List *list);
bool isEmptyList(const List *list);
int getFirst(const List *list);
int getLast(const List *list);
List *removeFirst(const List *list);
void printList(const List *list);
bool areListsEqual(const List *list1, const List *list2);

#endif // LIST_H