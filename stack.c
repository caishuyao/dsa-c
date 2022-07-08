#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
void logger(char * msg){
  printf("%s\n",msg);
}
void StackInitialise(Stack * stack){
  stack->size=0;
  stack->top=NULL;
}

bool IsStackFULL(Stack * stack){
  return (stack->size  ==  MAXSTACK );
  }
bool IsStackEmpty(Stack * stack){
return(stack->size  ==0);
  }
int SizeOfStack(Stack * stack){
return  stack->size;
}

bool StackPush(Stack * stack, Item * item){
if (!IsStackFULL(stack)){
Node * node=(Node *)malloc(sizeof(Node));
  node->item = (Item *)malloc(sizeof(Item));
*(node->item)= *item;
  node->next =stack->top;
  stack->top = node;
  stack->size++;
  return true;
}
else
return false;
  }

bool StackPop(Stack * stack, Item * item){
if (!IsStackEmpty(stack)){
  *item= *(stack->top->item);
  stack->top=stack->top->next;
  stack->size--;
  return true;
}
else
return false;
}

bool StackClear(Stack * stack){
  return true;
}