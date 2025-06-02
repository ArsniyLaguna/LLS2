#include "stack.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void test_stack_1() {
  // Arrange
  Stack *stack = createStack();

  // Act
  pushFront(stack, 10);
  pushBack(stack, 20);
  pushMiddle(stack, 15, 1);

  // Assert
  assert(10 == findElement(stack, 0));
  freeStack(stack);
}

void test_stack_2() {

  Stack *stack = createStack();

  pushFront(stack, 30);
  pushBack(stack, 25);
  pushMiddle(stack, 15, 0);

  assert(30 == findElement(stack, 1));
  freeStack(stack);
}

int main() {

  test_stack_1();
  test_stack_2();
  return 0;
}
