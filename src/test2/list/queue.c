#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

FunctionalQueue *createQueue() {
  FunctionalQueue *queue = (FunctionalQueue *)malloc(sizeof(FunctionalQueue));
  if (queue == NULL) {
    return NULL;
  }

  queue->front = createList();
  queue->rear = createList();
  queue->size = 0;

  if (queue->front == NULL || queue->rear == NULL) {
    if (queue->front != NULL)
      destroyList(queue->front);
    if (queue->rear != NULL)
      destroyList(queue->rear);
    free(queue);
    return NULL;
  }

  return queue;
}

void destroyQueue(FunctionalQueue *queue) {
  if (queue == NULL) {
    return;
  }

  if (queue->front != NULL) {
    destroyList(queue->front);
  }

  if (queue->rear != NULL) {
    destroyList(queue->rear);
  }

  free(queue);
}

FunctionalQueue *copyQueue(const FunctionalQueue *queue) {
  if (queue == NULL) {
    return NULL;
  }

  FunctionalQueue *newQueue = createQueue();
  if (newQueue == NULL) {
    return NULL;
  }

  destroyList(newQueue->front);
  destroyList(newQueue->rear);

  newQueue->front = copyList(queue->front);
  newQueue->rear = copyList(queue->rear);
  newQueue->size = queue->size;

  if (newQueue->front == NULL || newQueue->rear == NULL) {
    destroyQueue(newQueue);
    return NULL;
  }

  return newQueue;
}

static FunctionalQueue *normalize(FunctionalQueue *queue) {
  if (queue == NULL) {
    return NULL;
  }

  if (isEmptyList(queue->front)) {
    List *newFront = reverseList(queue->rear);
    if (newFront != NULL) {
      destroyList(queue->front);
      queue->front = newFront;
      queue->rear = createList();
    }
  }

  return queue;
}

FunctionalQueue *enqueue(FunctionalQueue *queue, int value) {
  if (queue == NULL) {
    return NULL;
  }

  FunctionalQueue *newQueue = copyQueue(queue);
  if (newQueue == NULL) {
    return NULL;
  }

  List *newRear = appendToList(newQueue->rear, value);
  if (newRear == NULL) {
    destroyQueue(newQueue);
    return NULL;
  }

  destroyList(newQueue->rear);
  newQueue->rear = newRear;
  newQueue->size++;

  return normalize(newQueue);
}

FunctionalQueue *dequeue(FunctionalQueue *queue) {
  if (queue == NULL || isEmptyQueue(queue)) {
    return createQueue(); // Возвращаем новую пустую очередь
  }

  FunctionalQueue *newQueue = copyQueue(queue);
  if (newQueue == NULL) {
    return createQueue();
  }

  if (isEmptyList(newQueue->front)) {
    normalize(newQueue);
  }

  if (!isEmptyList(newQueue->front)) {
    List *newFront = removeFirst(newQueue->front);
    destroyList(newQueue->front);
    newQueue->front = newFront;
    newQueue->size--;
  }

  return normalize(newQueue);
}

int peek(FunctionalQueue *queue) {
  if (queue == NULL || isEmptyQueue(queue)) {
    return -1;
  }

  if (isEmptyList(queue->front)) {
    normalize((FunctionalQueue *)queue); // Небезопасно, но для чтения ок
  }

  if (!isEmptyList(queue->front)) {
    return getFirst(queue->front);
  }

  return -1;
}

int queueSize(FunctionalQueue *queue) {
  return queue == NULL ? 0 : queue->size;
}

bool isEmptyQueue(FunctionalQueue *queue) {
  return queue == NULL || queue->size == 0;
}

void printQueue(FunctionalQueue *queue) {
  if (queue == NULL) {
    printf("NULL queue\n");
    return;
  }

  printf("Queue (size=%d):\n", queue->size);
  printf("  Front: ");
  printList(queue->front);
  printf("\n");
  printf("  Rear : ");
  printList(queue->rear);
  printf("\n");

  printf("  In order: [");
  if (!isEmptyList(queue->front)) {
    printList(queue->front);
  }

  if (!isEmptyList(queue->rear)) {
    List *reversedRear = reverseList(queue->rear);
    if (!isEmptyList(queue->front) && !isEmptyList(reversedRear)) {
      printf(", ");
    }
    printList(reversedRear);
    destroyList(reversedRear);
  }
  printf("]\n");
}