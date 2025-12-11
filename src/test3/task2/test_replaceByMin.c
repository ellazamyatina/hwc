#include "replaceByMin.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// one function got running all the tests
bool runTest(const char *input, const char *expected) {
  char buf[100];
  strcpy(buf, input);
  makeMinNumber(buf);

  bool ok = (strcmp(buf, expected) == 0);

  printf("test(%s) %s, ожидалось %s : %s\n", input, buf, expected,
         ok ? "passed" : "failed");

  return ok;
}

bool test1(void) { return runTest("5310", "1035"); }
bool test2(void) { return runTest("1002", "1002"); }
bool test3(void) { return runTest("987654", "456789"); }
bool test4(void) { return runTest("2222", "2222"); }
bool test5(void) { return runTest("1010", "1001"); }

int main(void) {
  bool ok = true;

  ok = ok && test1();
  ok = ok && test2();
  ok = ok && test3();
  ok = ok && test4();
  ok = ok && test5();

  if (ok)
    printf("All tests passed\n");
  else
    printf("Some of tests were failed\n");
  return ok ? 0 : 1;
}
