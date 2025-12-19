#include <stdio.h>
#include <string.h>

int main() {
  char input[1000] = "\0";
  int balance = 0;
  printf("Введите строку для проверки баланса скобок: ");
  fgets(input, sizeof(input), stdin);
  input[strlen(input) - 1] = '\0';

  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == '(') {
      balance++;
    } else if (input[i] == ')') {
      balance--;

      if (balance < 0) {
        break;
      }
    }
  }

  if (balance == 0) {
    printf("Скобки сбалансированы\n");
  } else {
    printf("Скобки НЕ сбалансированы\n");
  }

  return 0;
}