#include <stdio.h>
#include <math.h>

int main() {
    int x = 0;        
    int result = 0;   
    int x2 = 0;       
    int tempVar1 = 0;    
    int tempVar2 = 0;    
    int tempVar3 = 0;    
    
    printf("Введите значение x: ");
    scanf("%d", &x);
    
    x2 = pow(x,2);
    
    tempVar1 = x2 + x;   
    tempVar2 = x2 + 1;   
    tempVar3 = tempVar1 * tempVar2;
    
    result = tempVar3 + 1;
    
    printf("Результат: %d\n", result);
    
    return 0;
}
