#include <stdio.h>

int main()
{
    char str[100] = "\0";
    char sub[100] = "\0";
    int count = 0;

    printf("Введите основную строку: ");
    scanf("%s", str);

    printf("Введите подстроку: ");
    scanf("%s", sub);

    for (int i = 0; str[i] != '\0'; i++) {
        int j;
        for (j = 0; sub[j] != '\0'; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (sub[j] == '\0') {
            count++;
        }
    }

    printf("Количество вхождений: %d\n", count);

    return 0;
}