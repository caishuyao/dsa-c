#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void pushNumber(Stack * stack, float number){
  Item item;
  item.isNumber=true;
  item.data.number=number;
  StackPush(stack, &item);
}

void popNumber(Stack * stack, float * pnumber){
  Item item;
  StackPop(stack, &item);
  *pnumber = item.data.number;
}

void pushOperator(Stack * stack,char operator){
Item item;
  item.isNumber=false;
  item.data.operator=operator;
  StackPush(stack, &item); 
}

void popOperator(Stack * stack, char * poperator){
 Item item;
  StackPop(stack, &item);
  *poperator =item.data.operator;
}

void compute(Stack * operators,Stack * numbers){
  char  operator;
  float no1,no2;
  popNumber(numbers, &no1);
  popNumber(numbers, &no2);

  popOperator(operators,&operator);
  printf("%f%c%f\n",no2,operator,no1);
  if(operator=='+'){
    pushNumber(numbers,no2+no1);
  }else if(operator=='-'){
    pushNumber(numbers,no2-no1);
  }else if(operator=='*'){
    pushNumber(numbers,no2*no1);
  }
  if(operator=='/'){
    pushNumber(numbers,no2/no1);
  }
}

bool isDigit(char ch){
  return (ch>='0' && ch<='9')?true:false;
}
int getPriority(char op){
  return (op=='*'||op=='/') ? 1 :0;
}
bool prior(char op1,char op2){
  bool ret = getPriority(op1)>=getPriority(op2);
  return ret;
}
bool checkOperator(Stack * stack,char op){
      char previous;
      popOperator(stack,&previous);
      pushOperator(stack,previous);
     return prior(previous,op);
}
float cc(char ch){
  return ch-'0';
}
int test(){
  char expression[100]="1+2*";
  expression[17]='\0';
  Stack operators,numbers; 
  StackInitialise(&operators);
  StackInitialise(&numbers);
  int len = strlen(expression);
  for(int i =0;i<len;i++){
    char ch = expression[i];
  if(!isDigit(ch)){
      while(SizeOfStack(&operators)>0&&checkOperator(&operators,ch)){
        compute(&operators,  &numbers );
      }
       pushOperator(&operators,ch);
    }  else{
      pushNumber(&numbers, cc(ch));
    }
    }
      while(SizeOfStack(&operators)>0){
          compute(&operators,  &numbers ) ;
      }
  float result;
   popNumber(&numbers, &result);
    
     printf("result=%f\n",result);
  return 0;
}


