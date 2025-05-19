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

LinkedList *createLinkedList();
void freeLinkedList(LinkedList *list);
void insertAtBeginning(LinkedList *list, int data);
void insertAtEnd(LinkedList *list, int data);
void insertAtPosition(LinkedList *list, int data, int position);
int deleteNode(LinkedList *list, int position);
int getAtPosition(LinkedList *list, int position);
int getSize(LinkedList *list);
void printLinkedList(LinkedList *list);

#endif