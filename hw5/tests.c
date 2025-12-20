#include "sortList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_insertSorted(Node** head, int value)
{
    Node* newNode = createNode(value);
    if (newNode == NULL)
        return;

    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void test_deleteValue(Node** head, int value)
{
    if (*head == NULL)
        return;

    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void test_freeList(Node* head)
{
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int getListSize(Node* head)
{
    int size = 0;
    Node* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool isListSorted(Node* head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}

static bool testEmptyList()
{
    Node* head = NULL;
    bool result = (getListSize(head) == 0 && isListSorted(head));
    printf("emptyList: %s\n", result ? "PASS" : "FAIL");
    return result;
}

static bool testInsertSorted()
{
    Node* head = NULL;
    test_insertSorted(&head, 3);
    test_insertSorted(&head, 1);
    test_insertSorted(&head, 2);
    bool result = (getListSize(head) == 3 && isListSorted(head));
    printf("insertSorted: %s\n", result ? "PASS" : "FAIL");
    freeList(head);
    return result;
}

static bool testDuplicates()
{
    Node* head = NULL;
    test_insertSorted(&head, 2);
    test_insertSorted(&head, 2);
    test_insertSorted(&head, 1);
    bool result = (getListSize(head) == 3 && isListSorted(head));
    printf("duplicates: %s\n", result ? "PASS" : "FAIL");
    freeList(head);
    return result;
}

static bool testDeleteOperations()
{
    Node* head = NULL;
    test_insertSorted(&head, 1);
    test_insertSorted(&head, 2);
    test_insertSorted(&head, 3);

    test_deleteValue(&head, 2);
    bool result = (getListSize(head) == 2 && isListSorted(head));
    test_deleteValue(&head, 5);
    result &= (getListSize(head) == 2 && isListSorted(head));
    test_deleteValue(&head, 1);
    result &= (getListSize(head) == 1 && isListSorted(head));
    printf("deleteOperations: %s\n", result ? "PASS" : "FAIL");
    test_freeList(head);
    return result;
}

static bool testComplexScenario()
{
    Node* head = NULL;

    test_insertSorted(&head, 5);
    test_insertSorted(&head, 1);
    test_insertSorted(&head, 3);
    test_insertSorted(&head, -2);

    test_deleteValue(&head, 3);
    test_insertSorted(&head, 4);
    test_deleteValue(&head, 1);

    bool result = (getListSize(head) == 3 && isListSorted(head));
    printf("complexScenario: %s\n", result ? "PASS" : "FAIL");
    test_freeList(head);
    return result;
}

int runAllTests()
{
    printf("ТЕСТЫ СОРТИРОВАННОГО СПИСКА\n\n");

    bool results[] = { testEmptyList(), testInsertSorted(), testDuplicates(),
        testDeleteOperations(), testComplexScenario() };

    int total = sizeof(results) / sizeof(results[0]);
    int failed = 0;

    for (int i = 0; i < total; i++) {
        if (!results[i])
            failed++;
    }

    printf("\nИтог: тестов пройдено: %d, не пройдено: %d\n", total - failed,
        failed);
    return failed;

    if (failed == 0) {
        printf("ВСЕ ТЕСТЫ ПРОЙДЕНЫ\n");
    } else {
        printf("ЕСТЬ ОШИБКИ\n");
    }
    return failed;
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        return runAllTests();
    }

    printf("Для запуска тестов используйте: %s --test\n", argv[0]);
    return 0;
}