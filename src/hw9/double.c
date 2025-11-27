#include "double.h"
#include <stdint.h>
#include <stdio.h>

typedef union {
  double value;
  uint64_t bits;
} DoubleUnion;

void analyzeDouble(double number) {
  DoubleUnion du;
  du.value = number;
  uint64_t bits = du.bits;

  int sign = (bits >> 63) & 1;
  int exponent = (bits >> 52) & 0x7FF;
  uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

  if (exponent == 0x7FF) {
    if (mantissa == 0) {
      printf(sign ? "-inf" : "+inf");
    } else {
      printf("NaN");
    }
    return;
  }

  if (exponent == 0) {
    if (mantissa == 0) {
      printf(sign ? "-0.0*2^0" : "+0.0*2^0");
      return;
    }
    exponent = -1022;
  } else {
    exponent -= 1023;
    mantissa |= (1ULL << 52);
  }

  printf(sign ? "-" : "+");
  double m = (double)mantissa / (1ULL << 52);
  printf("%.20lf*2^%d", m, exponent);
}