#include <stdio.h>

int integer_division(int a, int b) {
  if (b == 0) {
    printf("Ошибка: деление на ноль\n");
    return 0;
  }

  int sign = 1;
  if ((a * b) < 0) {
    sign = -1;
  }

  int ua = (a < 0) ? -a : a;
  int ub = (b < 0) ? -b : b;
  int quotient = 0;

  while (ua >= ub) {
    ua -= ub;
    quotient++;
  }

  return sign * quotient;
}

int main() {
  int a = 0;
  int b = 0;

  printf("Введите a и b: ");
  scanf("%d %d", &a, &b);

  int result = integer_division(a, b);

  printf("Неполное частное: %d\n", result);

  return 0;
}