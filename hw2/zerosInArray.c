#include <stdio.h>

int main() {
  int n = 0;
  int count = 0;

  printf("Введите количество элементов в массиве: ");
  scanf("%d", &n);

  int arr[n];

  printf("Введите элементы массива:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      count++;
    }
  }

  printf("Количество нулевых элементов: %d\n", count);

  return 0;
}
