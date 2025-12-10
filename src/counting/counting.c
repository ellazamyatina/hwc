#include <stdio.h>
#include <stdlib.h>

typedef struct Warrior {
  int number;
  struct Warrior *next;
} Warrior;

// implementation of circle(cycle) list
Warrior *createCircle(int n) {
  if (n <= 0)
    return NULL;

  Warrior *first = (Warrior *)malloc(sizeof(Warrior));
  first->number = 1;

  Warrior *current = first;
  for (int i = 2; i <= n; i++) {
    Warrior *newWarrior = (Warrior *)malloc(sizeof(Warrior));
    newWarrior->number = i;
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
    prev->next = current->next;
    Warrior *toDelete = current;
    current = current->next;
    free(toDelete);
  }

  int survivor = current->number;
  free(current);
  return survivor;
}

int main() {
  int n, m;

  printf("Введите n: ");
  scanf("%d", &n);

  printf("Введите m: ");
  scanf("%d", &m);

  int survivor = josephus(n, m);
  printf("Выживший воин: %d\n", survivor);

  return 0;
}