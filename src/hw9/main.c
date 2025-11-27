#include "double.h"
#include <stdio.h>

int main() {
  double number;
  printf("Введите число: ");
  scanf("%lf", &number);

  printf("Результат: ");
  analyzeDouble(number);
  printf("\n");

  return 0;
}