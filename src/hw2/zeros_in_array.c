#include <stdio.h>

int main() {
    int arr[10];      
    int count = 0;    
    int i = 0;        
    
    printf("Введите 10 чисел: ");
    
    for(i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < 10; i++) {
        if(arr[i] == 0) {
            count++;
        }
    }
    
    printf("Количество нулевых элементов: %d\n", count);
    
    return 0;
}