#include "replaceByMin.h"
#include <stdio.h>

int main(void)
{
    char s[100];

    printf("Введите число: ");
    if (scanf("%99s", s) != 1)
        return 1;

    makeMinNumber(s);

    printf("Наименьшее число: %s\n", s);
    return 0;
}