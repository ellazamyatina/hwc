#include "sorting.h"
#include <stdio.h>

int main()
{
    int numbers[100];
    int count = 0;

    printf("Введите до 100 целых чисел, разделенных пробелами:\n");

    while (count < 100 && scanf("%d", &numbers[count]) == 1) {
        count++;
    }

    if (count == 0) {
        printf("Не введено ни одного числа.\n");
        return 0;
    }

    printf("Исходный массив: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int countOfMoved = bubbleSort(numbers, count) * 2;

    printf("Отсортированный массив: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Количество перемещенных элементов: %d\n", countOfMoved);
    printf("Количество элементов, участвовавших в сортировке: %d\n", count);

    return countOfMoved;
}