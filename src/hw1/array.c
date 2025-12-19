#include <stdio.h>
#include <stdlib.h>

void swopPartsOfArray(int* array, int left, int right)
{
    while (left < right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        ++left;
        --right;
    }
}

int main()
{
    int m = 0;
    int n = 0;

    printf("Введите m и n: ");
    scanf("%d %d", &m, &n);

    int len = n + m;
    int* array = malloc(len * sizeof(int));

    printf("Введите %d элементов массива: ", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &array[i]);
    }

    printf("Исходный массив: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    swopPartsOfArray(array, 0, m - 1);
    swopPartsOfArray(array, m, m + n - 1);
    swopPartsOfArray(array, 0, m + n - 1);

    printf("После обмена: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}