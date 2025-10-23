#include "stack.c"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPreoritite(char op) {
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/') {
    return 2;
  }
  return 0;
}

char *convertString(char *string, int len) {
  struct Stack stack = newStack();
  char *queue = malloc(101 * sizeof(char));
  int countForQueue = 0;
  int i = 0;
  while (i != len) {
    if (isdigit(string[i])) {
      queue[countForQueue] = string[i];
      ++countForQueue;
    }
    if (string[i] == '(') {
      push(&stack, string[i]);
    } else if (string[i] == ')') {
      while ((stack.head != NULL) && (peek(&stack) != '(')) {
        queue[countForQueue] = pop(&stack);
        ++countForQueue;
      }
      if ((stack.head != NULL) && (peek(&stack) == '(')) {
        pop(&stack);
      } else if (stack.head == NULL) {
        deleteStack(&stack);
        return "Нет открывающей скобки";
      }
    }
    if ((string[i] == '+') || (string[i] == '-') || (string[i] == '*') ||
        (string[i] == '/')) {
      while ((stack.head != NULL) &&
             (getPreoritite(string[i]) <= getPreoritite(peek(&stack)))) {
        queue[countForQueue] = pop(&stack);
        ++countForQueue;
      }
      push(&stack, string[i]);
    }
    ++i;
  }
  if (stack.head != NULL) {
    while (stack.head != NULL) {
      if (peek(&stack) == '(') {
        deleteStack(&stack);
        return "Нет закрывающей скобки";
      }
      queue[countForQueue] = pop(&stack);
      ++countForQueue;
    }
  }
  deleteStack(&stack);
  queue[countForQueue] = '\0';
  return queue;
}

int main() {
  char *arifmeticExpression = malloc(101 * sizeof(char));
  printf("Введите выражение:\n");
  fgets(arifmeticExpression, 101, stdin);
  char *queue = convertString(arifmeticExpression, strlen(arifmeticExpression));
  for (unsigned i = 0; i <= strlen(queue); i++) {
    if (i == 0) {
      printf("%c", queue[i]);
    } else if (i == strlen(queue)) {
      printf("%c\n", queue[i]);
    } else {
      printf(" %c ", queue[i]);
    }
  }
  free(arifmeticExpression);
  return 0;
}