#include "binary.h"
#include <stdio.h>

int main() {
  int num1, num2;
  char binary1[MAX_BINARY_LENGTH];
  char binary2[MAX_BINARY_LENGTH];
  char result[MAX_BINARY_LENGTH];

  printf("Введите первое число: ");
  scanf("%d", &num1);
  printf("Введите второе число: ");
  scanf("%d", &num2);

  toBinary(num1, binary1, BITS);
  toBinary(num2, binary2, BITS);

  addBinary(binary1, binary2, result, BITS);

  int decimalSum = binaryToDecimal(result, BITS);

  printAddition(binary1, binary2, result, num1, num2, decimalSum);

  return 0;
}