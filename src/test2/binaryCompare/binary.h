#ifndef BINARY_COMPARE_H
#define BINARY_COMPARE_H

#include <stdbool.h>

typedef struct {
  bool *bits;
  int length;
} BinaryNumber;

BinaryNumber *createBinaryNumber(const bool bits[], int length);
BinaryNumber *createBinaryNumberFromString(const char *str);
void destroyBinaryNumber(BinaryNumber *num);
void printBinaryNumber(const BinaryNumber *num);
int binaryToInt(const BinaryNumber *num);
BinaryNumber *intToBinary(int value, int maxBits);

int compareBinary(const BinaryNumber *a, const BinaryNumber *b);
bool isGreaterThan(const BinaryNumber *a, const BinaryNumber *b);
bool isLessThan(const BinaryNumber *a, const BinaryNumber *b);
bool isEqual(const BinaryNumber *a, const BinaryNumber *b);

int compareBinaryBitwise(const BinaryNumber *a, const BinaryNumber *b);
bool isGreaterThanBitwise(const BinaryNumber *a, const BinaryNumber *b);

#endif // BINARY_COMPARE_H