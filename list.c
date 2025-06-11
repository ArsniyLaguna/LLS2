#include "list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *createLinkedList(int *error) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL) {
        *error = 1;
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    *error = 0;
    return list;
}

void freeLinkedList(LinkedList *list) {
    if (list == NULL) return;
    
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int insertAtBeginning(LinkedList *list, int data) {
    if (list == NULL) return -1;
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -2;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return 0;
}

int insertAtEnd(LinkedList *list, int data) {
    if (list == NULL) return -1;
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -2;
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
    return 0;
}

int insertAtPosition(LinkedList *list, int data, int position) {
    if (list == NULL) return -1;
    if (position < 0 || position > list->size) {
        return -3;
    }

    if (position == 0) {
        return insertAtBeginning(list, data);
    } else if (position == list->size) {
        return insertAtEnd(list, data);
    } else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            return -2;
        }
        newNode->data = data;

        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->size++;
        return 0;
    }
}

int deleteNode(LinkedList *list, int position) {
    if (list == NULL) return -1;
    if (position < 0 || position >= list->size) {
        return -3;
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

int getAtPosition(LinkedList *list, int position, int *error) {
    if (list == NULL) {
        *error = -1;  
        return 0;
    }
    if (position < 0 || position >= list->size) {
        *error = -3;
        return 0;
    }

    Node *current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    *error = 0;
    return current->data;
}

int getSize(LinkedList *list, int *error) {
    if (list == NULL) {
        *error = -1;
        return 0;
    }
    *error = 0;
    return list->size;
}

void printLinkedList(LinkedList *list) {
    if (list == NULL) {
        return;
    }

    Node *current = list->head;
    printf("List: ");
    while (current != NULL) {
        current = current->next;
    }
}