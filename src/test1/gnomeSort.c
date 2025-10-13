#include <stdio.h>
#include <stdlib.h>

size_t n = 0; // size of array
long *arr = NULL;

void Read() {
  size_t i;
  printf("Размер массива: ");
  scanf("%u", &n);

  arr = (long *)calloc(n, sizeof(long));

  printf("Массив: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &(arr[i]));
  }
}
// implement sorting
void Do() {
  size_t i = 1;

  while (i < n) {
    if (i == 0) {
      i = 1;
    }
    if (arr[i - 1] <= arr[i]) {
      ++i;
    } else {
      long tmp = arr[i];
      arr[i] = arr[i - 1];
      arr[i - 1] = tmp;
      --i;
    }
  }
}

// result
void Write() {
  size_t i;

  printf("Результат: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void main() {
  Read();
  Do();
  Write();
}