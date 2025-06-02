
// Структура для узла стека
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Структура для стека
typedef struct {
  Node *top;
  int size;
} Stack;

Stack *createStack();
void pushFront(Stack *stack, int data);
void pushBack(Stack *stack, int data);
void pushMiddle(Stack *stack, int data, int position);
void pop(Stack *stack, int position);
int findElement(Stack *stack, int position);
int countElements(Stack *stack);
void freeStack(Stack *stack);
