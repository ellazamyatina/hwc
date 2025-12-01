#include "binary.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool testCreateAndConvert() {
  printf("Тест: Создание и конвертация\n");

  bool bits[] = {1, 0, 1, 1}; // 1011 = 11
  BinaryNumber *num = createBinaryNumber(bits, 4);

  bool result = num != NULL && binaryToInt(num) == 11 && num->length == 4;

  destroyBinaryNumber(num);
  return result;
}

bool testEqualNumbers() {
  printf("Тест: Равные числа\n");

  bool bits1[] = {1, 1, 0, 1}; // 1101 = 13
  bool bits2[] = {1, 1, 0, 1}; // 1101 = 13

  BinaryNumber *num1 = createBinaryNumber(bits1, 4);
  BinaryNumber *num2 = createBinaryNumber(bits2, 4);

  bool result = isEqual(num1, num2) && compareBinary(num1, num2) == 0 &&
                compareBinaryBitwise(num1, num2) == 0;

  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  return result;
}

bool testGreaterThanSameLength() {
  printf("Тест: A > B (одинаковая длина)\n");

  bool bits1[] = {1, 0, 1, 1, 0}; // 10110 = 22
  bool bits2[] = {1, 0, 0, 1, 1}; // 10011 = 19

  BinaryNumber *num1 = createBinaryNumber(bits1, 5);
  BinaryNumber *num2 = createBinaryNumber(bits2, 5);

  bool result = isGreaterThan(num1, num2) && compareBinary(num1, num2) > 0 &&
                isGreaterThanBitwise(num1, num2) &&
                compareBinaryBitwise(num1, num2) > 0;

  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  return result;
}

bool testLessThanSameLength() {
  printf("Тест: A < B (одинаковая длина)\n");

  bool bits1[] = {1, 0, 0, 1, 1}; // 10011 = 19
  bool bits2[] = {1, 0, 1, 1, 0}; // 10110 = 22

  BinaryNumber *num1 = createBinaryNumber(bits1, 5);
  BinaryNumber *num2 = createBinaryNumber(bits2, 5);

  bool result = isLessThan(num1, num2) && compareBinary(num1, num2) < 0 &&
                compareBinaryBitwise(num1, num2) < 0;

  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  return result;
}

bool testDifferentLengthGreater() {
  printf("Тест: A > B (разная длина)\n");

  bool bits1[] = {1, 1, 0, 1, 0, 1}; // 110101 = 53
  bool bits2[] = {1, 0, 1, 1};       // 1011 = 11

  BinaryNumber *num1 = createBinaryNumber(bits1, 6);
  BinaryNumber *num2 = createBinaryNumber(bits2, 4);

  bool result = isGreaterThan(num1, num2) && isGreaterThanBitwise(num1, num2);

  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  return result;
}

bool testDifferentLengthLess() {
  printf("Тест: A < B (разная длина)\n");

  bool bits1[] = {1, 0, 1};       // 101 = 5
  bool bits2[] = {1, 0, 1, 1, 0}; // 10110 = 22

  BinaryNumber *num1 = createBinaryNumber(bits1, 3);
  BinaryNumber *num2 = createBinaryNumber(bits2, 5);

  bool result = isLessThan(num1, num2) && compareBinaryBitwise(num1, num2) < 0;

  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  return result;
}

bool testStringCreation() {
  printf("Тест: Создание из строки\n");

  BinaryNumber *num = createBinaryNumberFromString("1100101"); // 101

  bool result = num != NULL && binaryToInt(num) == 101 && num->length == 7;

  destroyBinaryNumber(num);
  return result;
}

bool testBitManipulation() {
  printf("Тест: Битовые манипуляции\n");

  bool bits1[] = {1, 1, 1, 1, 1, 1, 1, 1}; // 255
  bool bits2[] = {1, 1, 1, 1, 1, 1, 1, 0}; // 254

  BinaryNumber *num1 = createBinaryNumber(bits1, 8);
  BinaryNumber *num2 = createBinaryNumber(bits2, 8);

  bool result =
      isGreaterThanBitwise(num1, num2) && compareBinaryBitwise(num1, num2) == 1;

  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  return result;
}

bool testZeroComparison() {
  printf("Тест: Сравнение с нулем\n");

  bool bits1[] = {0, 0, 0, 0}; // 0
  bool bits2[] = {0, 0, 0, 1}; // 1

  BinaryNumber *num1 = createBinaryNumber(bits1, 4);
  BinaryNumber *num2 = createBinaryNumber(bits2, 4);

  bool result =
      isLessThan(num1, num2) && compareBinaryBitwise(num1, num2) == -1;

  destroyBinaryNumber(num1);
  destroyBinaryNumber(num2);
  return result;
}

bool testEdgeCases() {
  printf("Тест: Крайние случаи\n");

  // Большое число
  bool bigBits[] = {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1}; // 16 бит
  BinaryNumber *bigNum = createBinaryNumber(bigBits, 16);

  // Маленькое число
  bool smallBits[] = {1}; // 1
  BinaryNumber *smallNum = createBinaryNumber(smallBits, 1);

  bool result1 = isGreaterThan(bigNum, smallNum);
  bool result2 = isGreaterThanBitwise(bigNum, smallNum);

  // Проверка NULL
  bool result3 = compareBinary(NULL, smallNum) == 0;
  bool result4 = compareBinaryBitwise(NULL, NULL) == 0;

  destroyBinaryNumber(bigNum);
  destroyBinaryNumber(smallNum);

  return result1 && result2 && result3 && result4;
}

int main() {
  printf("=== ТЕСТИРОВАНИЕ СРАВНЕНИЯ ДВОИЧНЫХ ЧИСЕЛ ===\n\n");

  bool allTestsPassed = true;
  int passedCount = 0;
  int totalTests = 0;

  bool (*testFunctions[])(void) = {
      testCreateAndConvert,       testEqualNumbers,
      testGreaterThanSameLength,  testLessThanSameLength,
      testDifferentLengthGreater, testDifferentLengthLess,
      testStringCreation,         testBitManipulation,
      testZeroComparison,         testEdgeCases};

  const char *testNames[] = {
      "Создание и конвертация",   "Равные числа",
      "A > B (одинаковая длина)", "A < B (одинаковая длина)",
      "A > B (разная длина)",     "A < B (разная длина)",
      "Создание из строки",       "Битовые манипуляции",
      "Сравнение с нулем",        "Крайние случаи"};

  int numTests = sizeof(testFunctions) / sizeof(testFunctions[0]);

  for (int i = 0; i < numTests; i++) {
    printf("Тест %d: %s\n", i + 1, testNames[i]);

    bool testResult = testFunctions[i]();

    if (testResult) {
      printf("✓ PASSED\n\n");
      passedCount++;
    } else {
      printf("✗ FAILED\n\n");
      allTestsPassed = false;
    }
    totalTests++;
  }

  printf("=================================\n");
  printf("Результаты: %d/%d тестов пройдено\n", passedCount, totalTests);

  if (allTestsPassed) {
    printf("ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО!\n");
    return 0;
  } else {
    printf("НЕКОТОРЫЕ ТЕСТЫ НЕ ПРОЙДЕНЫ\n");
    return 1;
  }
}