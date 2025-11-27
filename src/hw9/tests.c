#include "double.h"
#include <stdbool.h>
#include <stdio.h>

bool testNegative() {
  printf("Test -2.5: ");
  analyzeDouble(-2.5);
  printf("\n");
  return true;
}

bool testPositive() {
  printf("Test 8.0: ");
  analyzeDouble(8.0);
  printf("\n");
  return true;
}

bool testZero() {
  printf("Test 0.0: ");
  analyzeDouble(0.0);
  printf("\n");
  return true;
}

bool testExample() {
  printf("Test 12312.323: ");
  analyzeDouble(12312.323);
  printf("\n");
  return true;
}

int main() {
  printf("Тест Double\n\n");

  bool allPassed = true;

  if (testNegative()) {
    printf("testNegative PASSED\n\n");
  } else {
    printf("testNegative FAILED\n\n");
    allPassed = false;
  }

  if (testPositive()) {
    printf("testPositive PASSED\n\n");
  } else {
    printf("testPositive FAILED\n\n");
    allPassed = false;
  }

  if (testZero()) {
    printf("testZero PASSED\n\n");
  } else {
    printf("testZero FAILED\n\n");
    allPassed = false;
  }

  if (testExample()) {
    printf("testExample PASSED\n\n");
  } else {
    printf("testExample FAILED\n\n");
    allPassed = false;
  }

  if (allPassed) {
    printf("ALL TESTS HAVE PASSED\n");
  } else {
    printf("SOME TESTS FAILED\n");
  }

  return allPassed ? 0 : 1;
}