#include <stdio.h>

int main() {
    // Создаем массив для подсчета количества трехзначных чисел с каждой суммой цифр
    int count[28] = {0}; // суммы от 0 до 27
    
    // Подсчитываем сколько трехзначных чисел имеют каждую возможную сумму цифр
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
    
    // Количество билетов с заданной суммой в первой тройке цифр
    int tickets_with_sum = count[target_sum];
    
    // Для счастливых билетов вторая тройка цифр должна иметь такую же сумму
    int lucky_tickets = count[target_sum] * count[target_sum];
    
    printf("Счастливых билетов с суммой %d: %d\n", target_sum, lucky_tickets);
    
    return 0;
}