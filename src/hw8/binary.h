#ifndef BINARY_CALCULATOR_H
#define BINARY_CALCULATOR_H

#include <stddef.h>

#define BITS 32
#define MAX_BINARY_LENGTH (BITS + 1)

void toBinary(int number, char *binary, size_t bits);
void addBinary(const char *binary1, const char *binary2, char *result,
               size_t bits);
int binaryToDecimal(const char *binary, size_t bits);
void printAddition(const char *binary1, const char *binary2, const char *result,
                   int num1, int num2, int sum);

#endif