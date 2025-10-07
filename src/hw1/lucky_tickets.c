#include <stdio.h>

int main() {

    int count[28] = {0}; 

    for (int num = 0; num < 1000; num++) {
        int sum = (num / 100) + ((num / 10) % 10) + (num % 10);
        count[sum]++;
    }
    
    int target_sum;
    printf("Введите сумму трех цифр (0-27): ");
    scanf("%d", &target_sum);
    
    if (target_sum < 0 || target_sum > 27) {
        printf("Ошибка: сумма должна быть от 0 до 27\n");
        return 1;
    }
    
    int tickets_with_sum = count[target_sum];
    
    
    int lucky_tickets = count[target_sum] * count[target_sum];
    
    printf("Счастливых билетов с суммой %d: %d\n", target_sum, lucky_tickets);
    
    return 0;
}