#include <stdio.h>

int main()
{
    int count = 0;

    for (int num = 0; num <= 999999; num++) {

        int digit1 = num / 100000;
        int digit2 = (num / 10000) % 10;
        int digit3 = (num / 1000) % 10;
        int digit4 = (num / 100) % 10;
        int digit5 = (num / 10) % 10;
        int digit6 = num % 10;

        int sumOf1Part = digit1 + digit2 + digit3;
        int sumOf2Part = digit4 + digit5 + digit6;

        if (sumOf1Part == sumOf2Part) {
            count++;
        }
    }

    printf("Количество счастливых билетов: %d\n", count);

    return 0;
}