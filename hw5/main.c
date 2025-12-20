#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

void printMenu()
{
    printf("0 - Выйти\n");
    printf("1 - Добавить значение в сортированный список\n");
    printf("2 - Удалить значение из списка\n");
    printf("3 - Распечатать список\n");
    printf("Выберите операцию: ");
}
const char* getErrorMessage(ErrorCode error)
{
    switch (error) {
    case ok:
        return "Операция выполнена успешно";
    case error_memory:
        return "Ошибка, не удалось выделить память";
    case error_not_found:
        return "Ошибка, элемент не найден";
    case error_empty:
        return "Ошибка, список пуст";
    default:
        return "Неизвестная ошибка";
    }
}

int main(void)
{
    Node* head = NULL;
    int choice = -1;
    int value = -1;
    ErrorCode error = 0;

    printf("Программа для работы с сортированным списком\n");

    do {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice) {
        case 0:
            printf("Выход из программы...\n");
            break;

        case 1:
            printf("Введите значение для добавления: ");
            if (scanf("%d", &value) != 1) {
                printf("Jib,rf\n");
                while (getchar() != '\n')
                    ;
                break;
            }

            error = insertSorted(&head, value);
            if (error == ok) {
                printf("Значение %d добавлено в список.\n", value);
            } else {
                printf("%s\n", getErrorMessage(error));
            }

            break;

        case 2:
            printf("Введите значение для удаления: ");
            if (scanf("%d", &value) != 1) {
                printf("Ошибка ввода значения!\n");
                while (getchar() != '\n')
                    ;
                break;
            }

            error = deleteValue(&head, value);
            if (error == ok) {
                printf("Значение %d удалено из списка.\n", value);
            } else {
                printf("%s\n", getErrorMessage(error));
            }
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