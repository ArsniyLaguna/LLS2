#include "list.h"
#include <assert.h>
#include <stdio.h>

void testLinkedList() {
    int error;
    int value;

    LinkedList *list = createLinkedList(&error);
    assert(error == 0);
    assert(getSize(list, &error) == 0);
    assert(error == 0);

    error = insertAtBeginning(list, 10);
    assert(error == 0);
    assert(getSize(list, &error) == 1);
    assert(error == 0);
    assert(getAtPosition(list, 0, &value) == 0);
    assert(value == 10);

    error = insertAtEnd(list, 20);
    assert(error == 0);
    assert(getSize(list, &error) == 2);
    assert(error == 0);
    assert(getAtPosition(list, 1, &value) == 0);
    assert(value == 20);

    error = insertAtPosition(list, 15, 1);
    assert(error == 0);
    assert(getSize(list, &error) == 3);
    assert(error == 0);
    assert(getAtPosition(list, 1, &value) == 0);
    assert(value == 15);

    assert(getAtPosition(list, 0, &value) == 0);
    assert(value == 10);
    assert(getAtPosition(list, 1, &value) == 0);
    assert(value == 15);
    assert(getAtPosition(list, 2, &value) == 0);
    assert(value == 20);

    assert(deleteNode(list, 1, &value) == 0);
    assert(value == 15);
    assert(getSize(list, &error) == 2);
    assert(error == 0);
    assert(getAtPosition(list, 1, &value) == 0);
    assert(value == 20);

    assert(deleteNode(list, 0, &value) == 0);
    assert(value == 10);
    assert(getSize(list, &error) == 1);
    assert(error == 0);

    assert(deleteNode(list, 0, &value) == 0);
    assert(value == 20);
    assert(getSize(list, &error) == 0);
    assert(error == 0);

    freeLinkedList(list);
}

int main() {
    testLinkedList();
    printf("All tests passed successfully!\n");
    return 0;
}
