#ifndef LIST_H
#define LIST_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} LinkedList;

LinkedList *createLinkedList(int *error);
void freeLinkedList(LinkedList *list);
int insertAtBeginning(LinkedList *list, int data);
int insertAtEnd(LinkedList *list, int data);
int insertAtPosition(LinkedList *list, int data, int position);
int deleteNode(LinkedList *list, int position, int *data);
int getAtPosition(LinkedList *list, int position, int *data);
int getSize(LinkedList *list, int *error);

#endif
