#include <stdio.h>

int main() {
  int limit = 1000000;
  int a = 1; // last num
  int b = 1; // current fib
  int tempVar = 0;
  int sum = 0;

  while (b <= limit) {
    if (b % 2 == 0) {
      sum += b;
    }

    // calculate the next fib
    tempVar = a + b;
    a = b;
    b = tempVar;
  }

  printf("Сумма всех чётных чисел Фибоначчи до 1000000: %d\n", sum);

  return 0;
}
