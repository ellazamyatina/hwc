#include "binary.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compareAndPrint(const BinaryNumber *a, const BinaryNumber *b) {
  printf("Число A: ");
  printBinaryNumber(a);
  printf(" (десятичное: %d)\n", binaryToInt(a));

  printf("Число B: ");
  printBinaryNumber(b);
  printf(" (десятичное: %d)\n", binaryToInt(b));

  printf("\nМетод сравнения битов:\n");
  int result = compareBinary(a, b);
  if (result > 0) {
    printf("A > B\n");
  } else if (result < 0) {
    printf("A < B\n");
  } else {
    printf("A == B\n");
  }

  printf("\nМетод битовых манипуляций:\n");
  int resultBitwise = compareBinaryBitwise(a, b);
  if (resultBitwise > 0) {
    printf("A > B\n");
  } else if (resultBitwise < 0) {
    printf("A < B\n");
  } else {
    printf("A == B\n");
  }

  printf("\n");
  for (int i = 0; i < 50; i++)
    printf("-");
  printf("\n\n");
}

int main() {
  printf("Сравнение\n\n");

  // Eapmle 1: same length
  bool bits1[] = {1, 0, 1, 1, 0}; // 10110 = 22
  bool bits2[] = {1, 0, 0, 1, 1}; // 10011 = 19
  BinaryNumber *num1 = createBinaryNumber(bits1, 5);
  BinaryNumber *num2 = createBinaryNumber(bits2, 5);

  printf("Пример 1: Одинаковая длина\n");
  compareAndPrint(num1, num2);

  // Eample 2: diff length(A > B)
  bool bits3[] = {1, 1, 0, 1}; // 1101 = 13
  bool bits4[] = {1, 0, 1};    // 101 = 5
  BinaryNumber *num3 = createBinaryNumber(bits3, 4);
  BinaryNumber *num4 = createBinaryNumber(bits4, 3);

  printf("Пример 2: Разная длина (A > B)\n");
  compareAndPrint(num3, num4);

  // A <B
  bool bits5[] = {1, 0, 1};    // 101 = 5
  bool bits6[] = {1, 1, 0, 1}; // 1101 = 13
  BinaryNumber *num5 = createBinaryNumber(bits5, 3);
  BinaryNumber *num6 = createBinaryNumber(bits6, 4);

  printf("Пример 3: Разная длина (A < B)\n");
  compareAndPrint(num5, num6);

  // same nums
  bool bits7[] = {1, 0, 1, 0, 1}; // 10101 = 21
  bool bits8[] = {1, 0, 1, 0, 1}; // 10101 = 21
  BinaryNumber *num7 = createBinaryNumber(bits7, 5);
  BinaryNumber *num8 = createBinaryNumber(bits8, 5);

  printf("Пример 4: Равные числа\n");
  compareAndPrint(num7, num8);

  // string input
  BinaryNumber *num9 = createBinaryNumberFromString("11100101");  // 229
  BinaryNumber *num10 = createBinaryNumberFromString("11100100"); // 228

  printf("Пример 5: Строковый ввод\n");
  compareAndPrint(num9, num10);

  // large nums
  bool bits11[] = {1, 0, 1, 1, 0, 1, 0, 1, 1, 0}; // 1011010110 = 726
  bool bits12[] = {1, 0, 1, 1, 0, 1, 0, 1, 0, 1}; // 1011010101 = 725
  BinaryNumber *num11 = createBinaryNumber(bits11, 10);
  BinaryNumber *num12 = createBinaryNumber(bits12, 10);

  printf("Пример 6: Большие числа\n");
  compareAndPrint(num11, num12);

  // free
  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  destroyBinaryNumber(num3);
  destroyBinaryNumber(num4);
  destroyBinaryNumber(num5);
  destroyBinaryNumber(num6);
  destroyBinaryNumber(num7);
  destroyBinaryNumber(num8);
  destroyBinaryNumber(num9);
  destroyBinaryNumber(num10);
  destroyBinaryNumber(num11);
  destroyBinaryNumber(num12);

  return 0;
}