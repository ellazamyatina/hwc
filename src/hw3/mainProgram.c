#include <stdio.h>

extern int sortArray(int *array, int size);

int main() {
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

  int movedCount = sortArray(numbers, count);

  printf("Отсортированный массив: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  int moved2 = movedCount / 2;

  printf("Количество перемещенных элементов: %d\n", moved2);
  printf("Количество элементов, участвовавших в сортировке: %d\n", count);

  return movedCount;
}