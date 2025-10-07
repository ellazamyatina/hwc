#include <stdio.h>

int main() {
    char str[100] = "\0";   
    char sub[100] = "\0";    
    int count = 0;    
    int i = 0;      
    int j = 0;        
    
    printf("Введите основную строку: ");
    scanf("%s", &str);
    
    printf("Введите подстроку: ");
    scanf("%s", &sub);
    
    while (str[i] != '\0') {
        j = 0;
        while (sub[j] != '\0') {
            if (str[i + j] != sub[j]) {
                break;
            }
            j++;
        }
        if (sub[j] == '\0') {
            count++;
        }
        i++;
    }
    
    printf("Количество вхождений: %d\n", count);
    
    return 0;
}