#include "setOfNumbers.h"
#include <stdio.h>

int main(void) {
  int a[100];
  int n;

  readNumbers(a, &n);
  sortNumbers(a, n);

  int values[100];
  int counts[100];
  int m = compressNumbers(a, n, values, counts);

  printStats(values, counts, m);

  return 0;
}
