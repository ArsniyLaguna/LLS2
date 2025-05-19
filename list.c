
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *createLinkedList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (list == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->size = 0;
  return list;
}

void freeLinkedList(LinkedList *list) {
  Node *current = list->head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

void insertAtBeginning(LinkedList *list, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

void insertAtEnd(LinkedList *list, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    Node *current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
  list->size++;
}

void insertAtPosition(LinkedList *list, int data, int position) {
  if (position < 0 || position > list->size) {
    fprintf(stderr, "Invalid position\n");
    return;
  }

  if (position == 0) {
    insertAtBeginning(list, data);
  } else if (position == list->size) {
    insertAtEnd(list, data);
  } else {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
    newNode->data = data;

    Node *current = list->head;
    for (int i = 0; i < position - 1; i++) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
  }
}

int deleteNode(LinkedList *list, int position) {
  if (position < 0 || position >= list->size) {
    fprintf(stderr, "Invalid position\n");
    return -1;
  }

  Node *toDelete;
  if (position == 0) {
    toDelete = list->head;
    list->head = list->head->next;
  } else {
    Node *current = list->head;
    for (int i = 0; i < position - 1; i++) {
      current = current->next;
    }
    toDelete = current->next;
    current->next = toDelete->next;
  }

  int data = toDelete->data;
  free(toDelete);
  list->size--;
  return data;
}

int getAtPosition(LinkedList *list, int position) {
  if (position < 0 || position >= list->size) {
    fprintf(stderr, "Invalid position\n");
    return -1;
  }

  Node *current = list->head;
  for (int i = 0; i < position; i++) {
    current = current->next;
  }
  return current->data;
}

int getSize(LinkedList *list) { return list->size; }

void printLinkedList(LinkedList *list) {
  Node *current = list->head;
  printf("List: ");
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}