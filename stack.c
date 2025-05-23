#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
// Инициализация стека
Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

// Добавление элемента в начало стека
void pushFront(Stack *stack, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
  stack->size++;
}

// Добавление элемента в конец стека
void pushBack(Stack *stack, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (stack->top == NULL) {
    stack->top = newNode;
  } else {
    Node *temp = stack->top;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  stack->size++;
}

// Добавление элемента в середину стека по порядковому номеру
void pushMiddle(Stack *stack, int data, int position) {
  if (position < 0 || position > stack->size) {
    printf("Неверная позиция\n");
    return;
  }

  if (position == 0) {
    pushFront(stack, data);
    return;
  }

  if (position == stack->size) {
    pushBack(stack, data);
    return;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  Node *temp = stack->top;
  for (int i = 1; i < position; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  stack->size++;
}

// Удаление элемента из стека
void pop(Stack *stack, int position) {
  if (position < 0 || position >= stack->size) {
    printf("Неверная позиция\n");
    return;
  }

  Node *temp = stack->top;
  if (position == 0) {
    stack->top = temp->next;
    free(temp);
  } else {
    for (int i = 1; i < position; i++) {
      temp = temp->next;
    }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
  }
  stack->size--;
}

// Поиск элемента по порядковому номеру
int findElement(Stack *stack, int position) {
  if (position < 0 || position >= stack->size) {
    printf("Неверная позиция\n");
    return -1;
  }

  Node *temp = stack->top;
  for (int i = 0; i < position; i++) {
    temp = temp->next;
  }
  return temp->data;
}

// Подсчет количества элементов в стеке
int countElements(Stack *stack) { return stack->size; }

// Освобождение памяти стека
void freeStack(Stack *stack) {
  Node *temp;
  while (stack->top != NULL) {
    temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
  }
  free(stack);
}
