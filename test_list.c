
#include "list.h"
#include <assert.h>
#include <stdio.h>

void testLinkedList() {

  LinkedList *list = createLinkedList();
  assert(getSize(list) == 0);

  insertAtBeginning(list, 10);
  assert(getSize(list) == 1);
  assert(getAtPosition(list, 0) == 10);

  insertAtEnd(list, 20);
  assert(getSize(list) == 2);
  assert(getAtPosition(list, 1) == 20);

  insertAtPosition(list, 15, 1);
  assert(getSize(list) == 3);
  assert(getAtPosition(list, 1) == 15);

  assert(getAtPosition(list, 0) == 10);
  assert(getAtPosition(list, 1) == 15);
  assert(getAtPosition(list, 2) == 20);

  assert(deleteNode(list, 1) == 15);
  assert(getSize(list) == 2);
  assert(getAtPosition(list, 1) == 20);

  assert(deleteNode(list, 0) == 10);
  assert(getSize(list) == 1);

  assert(deleteNode(list, 0) == 20);
  assert(getSize(list) == 0);

  freeLinkedList(list);

  printf("All tests passed!\n");
}

int main() {
  testLinkedList();
  return 0;
}
