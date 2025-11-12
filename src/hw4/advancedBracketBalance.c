#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkBrackets(int counter, char *stringWithBrackets) {
  if (counter == 0) {
    return true;
  }

  struct Stack stack = newStack();

  for (int i = 0; i < counter; i++) {
    char current = stringWithBrackets[i];
    if (current == '(' || current == '{' || current == '[') {
      push(&stack, (int)current);
    } else if (current == ')' || current == '}' || current == ']') {
      if (stack.head == NULL) {
        deleteStack(&stack);
        return false;
      }

      int last = pop(&stack);

      if ((current == ')' && last != '(') || (current == '}' && last != '{') ||
          (current == ']' && last != '[')) {
        deleteStack(&stack);
        return false;
      }
    }
  }

  bool result = (stack.head == NULL);
  deleteStack(&stack);
  return result;
}

int main() {
  int len = 0;
  printf("Введите количество символов: \n");
  scanf("%d", &len);

  if (len <= 0) {
    printf("Некорректная длина\n");
    return 1;
  }

  printf("Введите строку: \n");
  getchar();

  char *stringWithBrackets = malloc((len + 1) * sizeof(char));

  int counter = 0;
  for (int i = 0; i < len; i++) {
    char tmp = ' ';
    scanf("%c", &tmp);
    if (tmp == '(' || tmp == ')' || tmp == '[' || tmp == ']' || tmp == '{' ||
        tmp == '}') {
      stringWithBrackets[counter] = tmp;
      ++counter;
    }
  }

  stringWithBrackets[counter] = '\0';

  bool isCorrect = checkBrackets(counter, stringWithBrackets);
  if (isCorrect) {
    printf("Баланс скобок соблюден\n");
  } else {
    printf("Баланс скобок НЕ соблюден\n");
  }

  free(stringWithBrackets);
  return 0;
}