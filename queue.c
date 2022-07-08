#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* 操作： 初始化队列 */
/* 前提条件： pq 指向一个队列 */
/* 后置条件： 队列被初始化为空 */
void InitializeQueue(Queue * pq){
  pq->front=NULL;
  pq->rear=NULL;
  pq->count=0;
}
/* 操作： 检查队列是否已满 */
/* 前提条件： pq 指向之前被初始化的队列
*/
/* 后置条件： 如果队列已满则返回true， 否则返回false */
bool QueueIsFull(const Queue * pq){
   return (pq->count==MAXQUEUE)?true:false;
  }
/* 操作： 检查队列是否为空 */
/* 前提条件： pq 指向之前被初始化的队列
*/
/* 后置条件： 如果队列为空则返回true， 否则返回false */
bool QueueIsEmpty(const Queue *pq){
    return (pq->count==0)?true:false;
}
/* 操作： 确定队列中的项数 */
/* 前提条件： pq 指向之前被初始化的队列
*/
/* 后置条件： 返回队列中的项数 */
int QueueItemCount(const Queue * pq){\
  return pq->count;
}
/* 操作： 在队列末尾添加项 */
/* 前提条件： pq 指向之前被初始化的队列
*/
/* item是要被添加在队列末尾的项 */
/* 后置条件： 如果队列不为空， item将被添加在队列的末
尾， */
/* 该函数返回true； 否则， 队列不改变， 该函数返回false*/
bool EnQueue(Item item, Queue * pq){
  if(QueueIsFull(pq)){
    return false;
  }
 Node *node = (Node *)malloc(sizeof(Node));
  node->item=item;
  node->next = NULL;
  if(pq->rear!=NULL){
  pq->rear->next=node;
  pq->rear = pq->rear->next;  
  }else{
    pq->rear=node;
    pq->front=node;
  }
  pq->count++;
  return true;
}
/* 操作： 从队列的开头删除项 */
/* 前提条件： pq 指向之前被初始化的队列
*/
/* 后置条件： 如果队列不为空， 队列首端的item将被拷贝到*pitem中
*/
/* 并被删除， 且函数返回true； */
/* 如果该操作使得队列为空， 则重置队列为
空 */
/* 如果队列在操作前为空， 该函数返回false
*/
bool DeQueue(Item *pitem, Queue * pq){
  if(QueueIsEmpty(pq)){
    return false;
  }
  *pitem=pq->front->item;
  
  pq->front=pq->front->next; 
  pq->count--;
  
  if(pq->count==0){
    InitializeQueue(pq);
  }
  return true;
}
/* 操作： 清空队列 */
/* 前提条件： pq 指向之
前被初始化的队列
*/
/* 后置条件： 队列被清空 */
void EmptyTheQueue(Queue * pq){
  
}

void TestQueue(){
  Queue que;
  printf("1\n");
  InitializeQueue(&que);
  printf("que is empty? %s\n",QueueIsEmpty(&que)==true?"true":"false");
  printf("que is full? %s\n",QueueIsFull(&que)==true?"true":"false");
  printf("que contains %d items\n",QueueItemCount(&que));
  for(int i=0;i<10;i++){
  Item item;
  item=random();
  printf("put one item(%d) into queue\n",item);
  EnQueue(item,&que);
    }
  printf("que is empty? %s\n",QueueIsEmpty(&que)==true?"true":"false");
  printf("que is full? %s\n",QueueIsFull(&que)==true?"true":"false");
  printf("que contains %d items\n",QueueItemCount(&que));
  for(int i=0;i<10;i++){
  Item data;
  DeQueue(&data,&que);
  printf("pop up one item(%d) from queue\n",data);
    }
  printf("que contains %d items\n",QueueItemCount(&que));
}