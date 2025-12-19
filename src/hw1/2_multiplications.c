#include <stdio.h>

int main() {
  int x = 0;

  printf("Введите значение x: ");
  scanf("%d", &x);

  int t = x * x;
  int result = (t + x) * (t + 1) + 1;

  printf("Результат: %d\n", result);

  return 0;
}
