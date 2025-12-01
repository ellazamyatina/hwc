#include "list.h"
#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool testCreateEmptyQueue() {

  FunctionalQueue *queue = createQueue();

  bool result = queue != NULL && isEmptyQueue(queue) && queueSize(queue) == 0;

  destroyQueue(queue);
  return result;
}

bool testEnqueueOneElement() {

  FunctionalQueue *queue = createQueue();
  queue = enqueue(queue, 42);

  bool result = queue != NULL && !isEmptyQueue(queue) &&
                queueSize(queue) == 1 && peek(queue) == 42;

  destroyQueue(queue);
  return result;
}

bool testEnqueueMultipleElements() {

  FunctionalQueue *queue = createQueue();
  queue = enqueue(queue, 1);
  queue = enqueue(queue, 2);
  queue = enqueue(queue, 3);

  bool result = queue != NULL && queueSize(queue) == 3 && peek(queue) == 1;

  destroyQueue(queue);
  return result;
}

bool testDequeueFromEmpty() {

  FunctionalQueue *queue = createQueue();
  FunctionalQueue *newQueue = dequeue(queue);

  bool result =
      newQueue != NULL && isEmptyQueue(newQueue) && queueSize(newQueue) == 0;

  destroyQueue(queue);
  destroyQueue(newQueue);
  return result;
}

bool testDequeueOneElement() {

  FunctionalQueue *queue = createQueue();
  queue = enqueue(queue, 100);
  queue = dequeue(queue);

  bool result = isEmptyQueue(queue);

  destroyQueue(queue);
  return result;
}

bool testPeekEmptyQueue() {

  FunctionalQueue *queue = createQueue();
  int value = peek(queue);

  bool result = value == -1;

  destroyQueue(queue);
  return result;
}

bool testListOperations() {

  int arr[] = {1, 2, 3};
  List *list = createListFromArray(arr, 3);
  bool step1 = listSize(list) == 3;

  List *reversed = reverseList(list);
  bool step2 = getFirst(reversed) == 3;

  List *appended = appendToList(list, 4);
  bool step3 = listSize(appended) == 4 && getLast(appended) == 4;

  List *noFirst = removeFirst(list);
  bool step4 = listSize(noFirst) == 2 && getFirst(noFirst) == 2;

  destroyList(list);
  destroyList(reversed);
  destroyList(appended);
  destroyList(noFirst);

  return step1 && step2 && step3 && step4;
}

bool testNormalization() {

  FunctionalQueue *queue = createQueue();

  queue = enqueue(queue, 1);
  queue = enqueue(queue, 2);
  queue = enqueue(queue, 3);

  queue = dequeue(queue);

  bool result = !isEmptyList(queue->front) && isEmptyList(queue->rear);

  destroyQueue(queue);
  return result;
}

int main() {
  printf("ТЕСТЫ ЧИСТО функциональной оереди\n\n");

  bool allTestsPassed = true;
  int passedCount = 0;
  int totalTests = 0;

  bool (*testFunctions[])(void) = {
      testCreateEmptyQueue, testEnqueueOneElement, testEnqueueMultipleElements,
      testDequeueFromEmpty, testDequeueOneElement, testPeekEmptyQueue,
      testListOperations,   testNormalization};

  const char *testNames[] = {"Создание пустой очереди",
                             "Добавление одного элемента",
                             "Добавление нескольких элементов",
                             "Удаление из пустой очереди",
                             "Удаление одного элемента",
                             "Peek пустой очереди",
                             "Операции со списками",
                             "Перенос из rear в front"};

  int numTests = sizeof(testFunctions) / sizeof(testFunctions[0]);

  for (int i = 0; i < numTests; i++) {
    printf("Тест %d: %s\n", i + 1, testNames[i]);

    bool testResult = testFunctions[i]();

    if (testResult) {
      printf("PASSED\n\n");
      passedCount++;
    } else {
      printf("FAILED\n\n");
      allTestsPassed = false;
    }
    totalTests++;
  }

  printf("Всего %d/%d тестов пройдено\n", passedCount, totalTests);

  if (allTestsPassed) {
    printf("ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО!\n");
    return 0;
  } else {
    printf("НЕКОТОРЫЕ ТЕСТЫ НЕ ПРОЙДЕНЫ\n");
    return 1;
  }
}