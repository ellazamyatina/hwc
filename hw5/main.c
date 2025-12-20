#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

void printMenu() {
  printf("0 - Выйти\n");
  printf("1 - Добавить значение в сортированный список\n");
  printf("2 - Удалить значение из списка\n");
  printf("3 - Распечатать список\n");
  printf("Выберите операцию: ");
}

int main(void) {
  Node *head = NULL;
  int choice = -1;
  int value = -1;

  printf("Программа для работы с сортированным списком\n");

  do {
    printMenu();
    scanf("%d", &choice);

    switch (choice) {
    case 0:
      printf("Выход из программы...\n");
      break;

    case 1:
      printf("Введите значение для добавления: ");
      scanf("%d", &value);
      insertSorted(&head, value);
      printf("Значение %d добавлено в список.\n", value);
      break;

    case 2:
      printf("Введите значение для удаления: ");
      scanf("%d", &value);
      deleteValue(&head, value);
      break;

    case 3:
      printList(head);
      break;

    default:
      printf("Неверный выбор! Попробуйте снова.\n");
      break;
    }
  } while (choice != 0);

  freeList(head);

  return 0;
}