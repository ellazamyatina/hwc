#ifndef SETOFNUMBERS_H
#define SETOFNUMBERS_H

void readNumbers(int *arr, int *n);
void sortNumbers(int *arr, int n);
int compressNumbers(const int *arr, int n, int *values, int *counts);
void printStats(const int *values, const int *counts, int m);

#endif