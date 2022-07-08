/* stack.h -- stack的接口 */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef union DATA {
    char operator;
    float number;
} Data;  

typedef struct ITEM{
  bool isNumber;
  Data data;
}Item;

#define MAXSTACK 20

typedef struct NODE{
Item *item;
struct NODE *next;
} Node;

typedef struct STACK{
int size ;
Node *top;
} Stack;

void StackInitialise(Stack * stack);

bool IsStackFULL(Stack * stack);

bool IsStackEmpty(Stack * stack);

int SizeOfStack(Stack * stack);

bool StackPush(Stack * stack, Item * item);

bool StackPop(Stack * stack, Item * item);

bool StackClear(Stack * stack);

void logger(char * msg);
#endif