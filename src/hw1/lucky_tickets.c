#include <stdio.h>

int main() {
    int sum3 = 0;        // sum of 3 num
    int count = 0;       
    int num = 0;         // num of the ticket
    int first_part = 0;  // first 3 num of ticket
    int second_part = 0; // last 3 num of ticket
    int sumOf1Part = 0;  
    int sumOf2Part = 0;  
    int digit1 = 0;      // first num of ticket's num
    int digit2 = 0;      
    int digit3 = 0;     
    int digit4 = 0;     
    int digit5 = 0;     
    int digit6 = 0;     
    
    printf("Введите сумму трех цифр: ");
    scanf("%d", &sum3);
    
    for(num = 0; num <= 999999; num++) {

        digit1 = num / 100000;
        digit2 = (num / 10000) % 10;
        digit3 = (num / 1000) % 10;
        digit4 = (num / 100) % 10;
        digit5 = (num / 10) % 10;
        digit6 = num % 10;
        
        sumOf1Part = digit1 + digit2 + digit3;
        sumOf2Part = digit4 + digit5 + digit6;
        
        if(sumOf1Part == sum3 && sumOf2Part == sum3) {
            count++;
        }
    }
    
    printf("Количество счастливых билетов с суммой %d: %d\n", sum3, count);
    
    return 0;
}