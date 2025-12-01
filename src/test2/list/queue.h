#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
#include <stdbool.h>

typedef struct {
  List *front;
  List *rear;
  int size;
} FunctionalQueue;

FunctionalQueue *createQueue();
void destroyQueue(FunctionalQueue *queue);
FunctionalQueue *enqueue(FunctionalQueue *queue, int value);
FunctionalQueue *dequeue(FunctionalQueue *queue);
int peek(FunctionalQueue *queue);
int queueSize(FunctionalQueue *queue);
bool isEmptyQueue(FunctionalQueue *queue);
void printQueue(FunctionalQueue *queue);
FunctionalQueue *copyQueue(const FunctionalQueue *queue);

#endif // QUEUE_H