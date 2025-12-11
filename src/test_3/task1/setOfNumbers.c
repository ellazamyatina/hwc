#include "setOfNumbers.h"
#include <stdio.h>

void readNumbers(int* arr, int* n)
{
    int x;
    *n = 0;
    printf("Введите числа(0 - конец):\n");
    while (1) {
        if (scanf("%d", &x) != 1)
            break;
        if (x == 0)
            break;
        arr[*n] = x;
        (*n)++;
    }
}

void sortNumbers(int* arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

int compressNumbers(const int* arr, int n, int* values, int* counts)
{
    if (n == 0)
        return 0;

    int m = 0;
    values[0] = arr[0];
    counts[0] = 1;
    m = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == values[m - 1])
            counts[m - 1]++;
        else {
            values[m] = arr[i];
            counts[m] = 1;
            m++;
        }
    }
    return m;
}

void printStats(const int* values, const int* counts, int m)
{
    printf("Количество\n");
    for (int i = 0; i < m; ++i)
        printf("%6d %10d\n", values[i], counts[i]);
}