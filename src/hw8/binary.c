#include "binary.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

void toBinary(int number, char *binary, size_t bits) {
  if (bits < 1 || bits > 64) {
    return;
  }
  unsigned int unsignedNum;
  if (number < 0) {
    unsignedNum = (1u << bits) + number;
  } else {
    unsignedNum = number;
  }

  for (int i = bits - 1; i >= 0; i--) {
    binary[i] = (unsignedNum & 1) ? '1' : '0';
    unsignedNum >>= 1;
  }
  binary[bits] = '\0';
}

void addBinary(const char *binary1, const char *binary2, char *result,
               size_t bits) {
  int carry = 0;

  for (int i = bits - 1; i >= 0; i--) {
    int bit1 = binary1[i] - '0';
    int bit2 = binary2[i] - '0';

    int sum = bit1 + bit2 + carry;
    result[i] = (sum % 2) + '0';
    carry = sum / 2;
  }
  result[bits] = '\0';
}

int binaryToDecimal(const char *binary, size_t bits) {
  int result = 0;
  int isNegative = (binary[0] == '1');

  if (isNegative) {
    unsigned int unsignedVal = 0;
    for (size_t i = 0; i < bits; i++) {
      unsignedVal <<= 1;
      unsignedVal |= (binary[i] == '1') ? 0 : 1; // reverse
    }
    result = -(unsignedVal + 1);
  } else {
    // for positive nums
    for (size_t i = 0; i < bits; i++) {
      result = result * 2 + (binary[i] - '0');
    }
  }

  return result;
}

void printAddition(const char *binary1, const char *binary2, const char *result,
                   int num1, int num2, int sum) {
  printf("Первое число: %d = %s\n", num1, binary1);
  printf("Второе число: %d = %s\n", num2, binary2);
  printf("Сложение в столбик:\n");
  printf("  %s\n", binary1);
  printf("+ %s\n", binary2);
  printf("  ");
  for (size_t i = 0; i < strlen(binary1); i++)
    printf("-");
  printf("\n");
  printf("  %s\n", result);
  printf("Сумма в двоичном: %s\n", result);
  printf("Сумма в десятичном: %d\n", sum);
}