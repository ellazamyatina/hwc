#include <ctype.h> //for checking type of char
#include <stdio.h>
#include <string.h>

int isPalindrome(const char *str) {
  int left = 0;
  int right = strlen(str) - 1;
  // skip spaces in string
  while (left < right) {

    while (left < right && str[left] == ' ') {
      left++;
    }

    while (left < right && str[right] == ' ') {
      right--;
    }
    left++;
    right--;
  }

  return 1;
}

int main() {
  char str[1000] = "\0";

  printf("Введите строку: ");
  fgets(str, sizeof(str), stdin);

  if (str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }

  if (isPalindrome(str)) {
    printf("Строка - палиндром\n");
  } else {
    printf("Строка не палиндром\n");
  }

  return 0;
}