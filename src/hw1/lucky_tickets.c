#include <stdio.h>

int countOfLuckyTickets()
{
    int sum[28] = { 0 }; // max sum of 3 digits is 27
    int count = 0;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                sum[i + j + k]++;

    for (int i = 0; i < 28; i++)
        count += sum[i] * sum[i];

    return count;
}

int main()
{
    printf("Количество счастливых билетиков:  %d\n", countOfLuckyTickets());
}