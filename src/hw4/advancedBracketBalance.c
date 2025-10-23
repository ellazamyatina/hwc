#include "stack.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkBrackets(int counter, char *stringWithBrackets) {
  if (counter == 0) {
    return false;
  }
  struct Stack stack = newStack();
  char tmp = ' ';
  for (int i = 0; i < counter; i++) {
    tmp = stringWithBrackets[i];
    if ((tmp == '(') || (tmp == '{') || (tmp == '[')) {
      push(&stack, tmp);
    } else if ((tmp == ')' || tmp == '}' || tmp == ']') &&
               (stack.head != NULL)) {
      char previousBracket = pop(&stack);
      if ((previousBracket + 1 == tmp) || (previousBracket + 2 == tmp)) {
        continue;
      } else {
        deleteStack(&stack);
        return false;
      }
    } else if ((tmp == ')' || tmp == '}' || tmp == ']') &&
               (stack.head == NULL)) {
      deleteStack(&stack);
      return false;
    }
  }
  if ((stack.head) == NULL) {
    deleteStack(&stack);
    return true;
  }
  deleteStack(&stack);
  return false;
}

int main() {
  int len = 0;
  printf("Введите количество символов: \n");
  scanf("%d", &len);
  printf("Введите строку: \n");
  getchar();
  char *stringWithBrackets = malloc(len * sizeof(char));
  int counter = 0;
  for (int i = 0; i < len; i++) {
    char tmp = ' ';
    scanf("%c", &tmp);

    if ((tmp == 40) || (tmp == 41) || (tmp == 91) || (tmp == 93) ||
        (tmp == 123) || (tmp == 125)) {
      stringWithBrackets[counter] = tmp;
      ++counter;
    }
  }
  bool isCorrect = checkBrackets(counter, stringWithBrackets);
  if (isCorrect) {
    printf("Балалс скобок соблюден\n");
  } else {
    printf("Баланс скобок НЕ соблюден\n");
  }
  free(stringWithBrackets);
  return 0;
}