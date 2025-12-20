#include "sorting.h"
#include <stdio.h>

int bubbleSort(int arr[], int n) {
  int movedElems = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        movedElems += 2;
      }
    }
  }
  return movedElems;
}
