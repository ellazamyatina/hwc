#include <stdio.h>

int main() {
    int arr[100];     
    int m = 0;        
    int n = 0;        
    int i = 0;        
    int tempVar = 0;    

    printf("Введите m и n: ");
    scanf("%d %d", &m, &n);
    
    printf("Введите %d элементов массива: ", m + n);
    for(i = 0; i < m + n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Исходный массив: ");
    for(i = 0; i < m + n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for(i = 0; i < m && i < n; i++) {
        tempVar = arr[i];
        arr[i] = arr[m + i];
        arr[m + i] = tempVar;
    }
    
    if(m > n) {
        for(i = n; i < m; i++) {
            tempVar = arr[i];

            for(int j = i; j < m + n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[m + n - 1] = tempVar;
        }
    } else if(n > m) {

        for(i = m + n - 1; i >= 2 * m; i--) {
            tempVar = arr[i];

            for(int j = i; j > m; j--) {
                arr[j] = arr[j - 1];
            }
            arr[m] = tempVar;
        }
    }
    
    printf("После обмена: ");
    for(i = 0; i < m + n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}