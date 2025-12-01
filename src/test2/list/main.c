#include "queue.h"
#include <stdio.h>

int main() {
  printf("ЧИСТО функциональная очередь\n\n");

  FunctionalQueue *queue = createQueue();

  printf("1. Создание пустой очереди:\n");
  printQueue(queue);
  printf("\n");

  printf("2. Добавление элементов 1, 2, 3:\n");
  queue = enqueue(queue, 1);
  printQueue(queue);
  queue = enqueue(queue, 2);
  printQueue(queue);
  queue = enqueue(queue, 3);
  printQueue(queue);
  printf("\n");

  printf("3. Удаление первого элемента:\n");
  queue = dequeue(queue);
  printQueue(queue);
  printf("\n");

  printf("4. Добавление элементов 4, 5:\n");
  queue = enqueue(queue, 4);
  printQueue(queue);
  queue = enqueue(queue, 5);
  printQueue(queue);
  printf("\n");

  printf("5. Несколько удалений:\n");
  queue = dequeue(queue);
  printQueue(queue);
  queue = dequeue(queue);
  printQueue(queue);
  printf("\n");

  printf("6. Проверка peek: %d\n", peek(queue));
  printf("7. Размер очереди: %d\n", queueSize(queue));
  printf("8. Очередь пуста? %s\n", isEmptyQueue(queue) ? "Да" : "Нет");
  printf("\n");

  printf("9. Удаление до пустой очереди:\n");
  queue = dequeue(queue);
  printQueue(queue);
  queue = dequeue(queue);
  printQueue(queue);
  printf("   Очередь пуста? %s\n", isEmptyQueue(queue) ? "Да" : "Нет");
  printf("\n");

  destroyQueue(queue);

  return 0;
}