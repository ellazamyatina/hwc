#include <stdio.h>

int sortArray(int *array, int size) {
  int movedCount = 0;

  if (size <= 1) {
    return 0;
  }

  int swapped;
  int n = size;

  do {
    swapped = 0;

    for (int i = 0; i < n - 1; i++) {
      if (array[i] > array[i + 1]) {

        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;

        movedCount++;

        swapped = 1;
      }
    }

    n--;

  } while (swapped);

  return movedCount;
}