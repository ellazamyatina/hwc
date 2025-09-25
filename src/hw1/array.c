#include <stdio.h>
#include <stdlib.h>

static void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

static void swapSegments(int* arr, int m, int n) {
    int total = m + n;
    reverse(arr, 0, total - 1);
    reverse(arr, 0, n - 1);
    reverse(arr, n, total - 1);
}

int main() {
    int m, n;
    
    printf("Enter m and n: ");
    scanf("%d %d", &m, &n);
    
    int total = m + n;
    int* arr = malloc(total * sizeof(int));
    
    printf("Enter %d numbers: ", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Before: ");
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    swapSegments(arr, m, n);
    
    printf("After:  ");
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}