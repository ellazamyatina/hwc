#include <stdio.h>
#include <stdlib.h>

typedef struct Warrior {
  int index;
  struct Warrior *next;
} Warrior;

Warrior* removeWarrior(Warrior *prev, Warrior *current) {
    if (prev == NULL || current == NULL) {
        return NULL;
    }
    prev->next = current->next;
    Warrior *nextWarrior = current->next;
    free(current);
    return nextWarrior;
}


// implementation of circle(cycle) list
Warrior *createCircle(int n) {
  if (n <= 0)
    return NULL;

  Warrior *first = (Warrior *)malloc(sizeof(Warrior));
  first->index = 1;

  Warrior *current = first;
  for (int i = 2; i <= n; i++) {
    Warrior *newWarrior = (Warrior *)malloc(sizeof(Warrior));
    newWarrior->index = i;
    current->next = newWarrior;
    current = newWarrior;
  }
  current->next = first;

  return first;
}

// function for finding survive warrior
int josephus(int n, int m) {
  if (n <= 0 || m <= 0)
    return -1;

  Warrior *current = createCircle(n);
  Warrior *prev = NULL;

  Warrior *temp = current;
  while (temp->next != current) {
    temp = temp->next;
  }
  prev = temp;

  while (current->next != current) {
    // find warrior #m
    for (int i = 1; i < m; i++) {
      prev = current;
      current = current->next;
    }

    // delete warrior #m
    current = removeWarrior(prev,current);
  }

  int survivor = current->index;
  free(current);
  return survivor;
}

int main() {
  int n = 0;
  int m = 0;

  printf("Введите n: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
      printf("Ошибка, n должно быть положительным числом\n");
      return 1;
  }

  printf("Введите m: ");
  if (scanf("%d", &m) != 1 || m <= 0) {
      printf("Ошибка, m должно быть положительным числом\n");
      return 1;
  }

  int survivor = josephus(n, m);
    
  if (survivor == -1) {
      printf("Ошибка, некорректные данные\n");
      return 1;
  }
    
  printf("Выживший воин: %d\n", survivor);

  return 0;
}