#include "binary.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BinaryNumber *createBinaryNumber(const bool bits[], int length) {
  if (length <= 0) {
    return NULL;
  }

  BinaryNumber *num = (BinaryNumber *)malloc(sizeof(BinaryNumber));
  if (num == NULL) {
    return NULL;
  }

  num->bits = (bool *)malloc(length * sizeof(bool));
  if (num->bits == NULL) {
    free(num);
    return NULL;
  }

  num->length = length;
  for (int i = 0; i < length; i++) {
    num->bits[i] = bits[i];
  }

  return num;
}

BinaryNumber *createBinaryNumberFromString(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  int length = strlen(str);
  if (length == 0) {
    return NULL;
  }

  BinaryNumber *num = (BinaryNumber *)malloc(sizeof(BinaryNumber));
  if (num == NULL) {
    return NULL;
  }

  num->bits = (bool *)malloc(length * sizeof(bool));
  if (num->bits == NULL) {
    free(num);
    return NULL;
  }

  num->length = length;
  for (int i = 0; i < length; i++) {
    if (str[i] == '1') {
      num->bits[i] = true;
    } else if (str[i] == '0') {
      num->bits[i] = false;
    } else {
      free(num->bits);
      free(num);
      return NULL;
    }
  }

  return num;
}

void destroyBinaryNumber(BinaryNumber *num) {
  if (num == NULL) {
    return;
  }

  if (num->bits != NULL) {
    free(num->bits);
  }

  free(num);
}

void printBinaryNumber(const BinaryNumber *num) {
  if (num == NULL || num->bits == NULL) {
    printf("NULL\n");
    return;
  }

  for (int i = 0; i < num->length; i++) {
    printf("%d", num->bits[i] ? 1 : 0);
  }
}

int binaryToInt(const BinaryNumber *num) {
  if (num == NULL || num->bits == NULL) {
    return 0;
  }

  int result = 0;
  int power = 1;

  for (int i = num->length - 1; i >= 0; i--) {
    if (num->bits[i]) {
      result += power;
    }
    power <<= 1; // Умножение на 2
  }

  return result;
}

BinaryNumber *intToBinary(int value, int maxBits) {
  if (value < 0 || maxBits <= 0) {
    return NULL;
  }

  BinaryNumber *num = (BinaryNumber *)malloc(sizeof(BinaryNumber));
  if (num == NULL) {
    return NULL;
  }

  num->bits = (bool *)malloc(maxBits * sizeof(bool));
  if (num->bits == NULL) {
    free(num);
    return NULL;
  }

  num->length = maxBits;

  for (int i = maxBits - 1; i >= 0; i--) {
    num->bits[i] = (value & 1) != 0;
    value >>= 1;
  }

  return num;
}

int compareBinary(const BinaryNumber *a, const BinaryNumber *b) {
  if (a == NULL || b == NULL || a->bits == NULL || b->bits == NULL) {
    return 0;
  }

  int lenA = a->length;
  int lenB = b->length;
  int maxLen = lenA > lenB ? lenA : lenB;

  for (int i = 0; i < maxLen; i++) {
    bool bitA = (i < lenA) ? a->bits[i] : false;
    bool bitB = (i < lenB) ? b->bits[i] : false;

    if (bitA && !bitB) {
      return 1;
    }
    if (!bitA && bitB) {
      return -1;
    }
  }

  return 0;
}

bool isGreaterThan(const BinaryNumber *a, const BinaryNumber *b) {
  return compareBinary(a, b) > 0;
}

bool isLessThan(const BinaryNumber *a, const BinaryNumber *b) {
  return compareBinary(a, b) < 0;
}

bool isEqual(const BinaryNumber *a, const BinaryNumber *b) {
  return compareBinary(a, b) == 0;
}

int compareBinaryBitwise(const BinaryNumber *a, const BinaryNumber *b) {
  if (a == NULL || b == NULL || a->bits == NULL || b->bits == NULL) {
    return 0;
  }

  int lenA = a->length;
  int lenB = b->length;

  int valueA = 0;
  int valueB = 0;

  // Преобразуем в целое число через битовые операции
  for (int i = 0; i < lenA; i++) {
    if (a->bits[lenA - 1 - i]) {
      valueA |= (1 << i);
    }
  }

  for (int i = 0; i < lenB; i++) {
    if (b->bits[lenB - 1 - i]) {
      valueB |= (1 << i);
    }
  }

  if (valueA > valueB) {
    return 1;
  } else if (valueA < valueB) {
    return -1;
  } else {
    return 0;
  }
}

bool isGreaterThanBitwise(const BinaryNumber *a, const BinaryNumber *b) {
  return compareBinaryBitwise(a, b) > 0;
}