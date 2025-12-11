#include "binary.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool testToBinary() {
  char binary[MAX_BINARY_LENGTH];
  toBinary(5, binary, 8);
  if (strcmp(binary, "00000101") != 0)
    return false;
  toBinary(-5, binary, 8);
  if (strcmp(binary, "11111011") != 0)
    return false;
  printf("testToBinary: PASSED\n");
  return true;
}

bool testAddBinary() {
  char binary1[] = "00000101";
  char binary2[] = "00000011";
  char result[MAX_BINARY_LENGTH];
  addBinary(binary1, binary2, result, 8);
  if (strcmp(result, "00001000") != 0)
    return false;
  printf("testAddBinary: PASSED\n");
  return true;
}

bool testBinaryToDecimal() {
  if (binaryToDecimal("00000101", 8) != 5)
    return false;
  if (binaryToDecimal("11111011", 8) != -5)
    return false;
  printf("testBinaryToDecimal: PASSED\n");
  return true;
}

bool testIntegration() {
  char b1[MAX_BINARY_LENGTH], b2[MAX_BINARY_LENGTH], res[MAX_BINARY_LENGTH];
  toBinary(10, b1, BITS);
  toBinary(15, b2, BITS);
  addBinary(b1, b2, res, BITS);
  if (binaryToDecimal(res, BITS) != 25)
    return false;
  printf("testIntegration: PASSED\n");
  return true;
}

int main() {
  printf("Running tests...\n\n");
  int passed = 0;
  if (testToBinary())
    passed++;
  if (testAddBinary())
    passed++;
  if (testBinaryToDecimal())
    passed++;
  if (testIntegration())
    passed++;
  printf("\nResult: %d/4 tests passed\n", passed);
  return (passed == 4) ? 0 : 1;
}