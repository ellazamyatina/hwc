#include <stdio.h>
#include <stdbool.h>
#include "list.h"

bool listEquals(Node *a, Node *b)
{
    while (a && b) {
        if (a->value != b->value)
            return false;
        a = a->next;
        b = b->next;
    }
    return a == NULL && b == NULL;
}

bool test_reverseEmpty(void)
{
    Node *head = NULL;
    Node *rev  = listReverse(head);
    bool ok = (rev == NULL);
    printf("test_reverseEmpty: %s\n", ok ? "passed" : "failed");
    return ok;
}

bool test_reverseOneList(void)
{
    Node *head = NULL;
    head = listPush(head, 42);

    Node *rev = listReverse(head);

    bool ok = (rev != NULL && rev->value == 42 && rev->next == NULL);
    printf("test_reverseOneList: %s\n", ok ? "passed" : "failed");

    listFree(rev);
    return ok;
}

bool test_reverseManyLists(void)
{
    Node *head = NULL;
    head = listPush(head, 1);
    head = listPush(head, 2);
    head = listPush(head, 3); 

    Node *expected = NULL;
    expected = listPush(expected, 3);
    expected = listPush(expected, 2);
    expected = listPush(expected, 1);  /

    Node *rev = listReverse(head);

    bool ok = listEqualsLists(rev, expected);
    printf("test_reverseManyLists: %s\n", ok ? "passed" : "failed");

    listFree(rev);
    listFree(expected);
    return ok;
}

int main(void)
{
    bool ok = true;
    ok = ok && test_reverseEmptyLists();
    ok = ok && test_reverseOneList();
    ok = ok && test_reverseManyLists();

    printf("Result: %s\n", ok ? "Tests successfully have passed" : "Some of tests have failed);
    return ok ? 0 : 1;
}
