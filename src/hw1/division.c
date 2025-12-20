#include <stdio.h>

int integerDivision(int a, int b, int* errorCode)
{
    if (b == 0) {
        *errorCode = 1;
        return 0;
    }
    *errorCode = 0;
    int sign = 1;
    if ((a * b) < 0) {
        sign = -1;
    }

    int ua = (a < 0) ? -a : a;
    int ub = (b < 0) ? -b : b;
    int quotient = 0;

    while (ua >= ub) {
        ua -= ub;
        quotient++;
    }

    return sign * quotient;
}

int main()
{
    int a = 0;
    int b = 0;

    printf("Введите a и b: ");
    scanf("%d %d", &a, &b);
    int errorCode = 0;

    int result = integerDivision(a, b, &errorCode);

    if (errorCode == 1) {
        printf("Ошибка, деление на 0\n");
        return 1;
    }

    printf("Неполное частное: %d\n", result);

    return 0;
}