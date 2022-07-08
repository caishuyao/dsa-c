#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* function prototypes */
/* operation: initialize a list */
/* preconditions: plist points to a list */
/* postconditions: the list is initialized to empty */
void InitializeList(List *plist)
{
  *plist = NULL;
}

bool ListIsEmpty(const List *plist)
{
  return (*plist != NULL) ? true : false;
}

bool ListIsFull(const List *plist)
{
  if (plist != NULL)
  {
    Node *c = (Node *)malloc(sizeof(Node));
    return c != NULL ? true : false;
  }
  return false;
}

/* operation: determine number of items in list */
/* plist points to an initialized list */
/* postconditions: function returns number of items in list */
unsigned int ListItemCount(const List *plist)
{
  if (plist == NULL)
    return 0;
  Node *Next = *plist;
  unsigned count = 0;
  while (Next != NULL)
  {
    count++;
    Next = Next->next;
  }
  return count;
}

/* operation: add item to end of list */
/* preconditions: item is an item to be added to list */
/* plist points to an initialized list */
/* postconditions: if possible, function adds item to end */
/* of list and returns True; otherwise the */
/* function returns False */
bool AddItem(Item item, List *plist)
{
  Node *Next = *plist;
  Node *hi = (Node *)malloc(sizeof(Node));
  if (hi == NULL)
  {
    return false;
  }
  hi->item = item;
  hi->next = NULL;
  if (Next == NULL)
  {
    *plist = hi;
  }
  else
  {
    while (Next->next != NULL)
    {
      Next = Next->next;
    }
    Next->next = hi;
  }
  return true;
}

/* operation: apply a function to each item in list */
/* plist points to an initialized list */
/* pfun points to a function that takes an */
/* Item argument and has no return value */
/* postcondition: the function pointed to by pfun is */
/* executed once for each item in the list */
void Traverse(const List *plist, void (*pfun)(Item item))
{
  Node *Next = (*plist)->next;
  for (int a = 0; Next != NULL; a++)
  {
    (*pfun)(Next->item);
    Next = Next->next;
  }
}
/* operation: free allocated memory, if any */
/* plist points to an initialized list */
/* postconditions: any memory allocated for the list is freed */
/* and the list is set to empty */
void EmptyTheList(List *plist)
{
  Node *next = *plist;
  while (next != NULL)
  {
    Node *tmp = next;
    next = next->next;
    free(tmp);
  }
}

void p(Item item)
{
  printf("item %s is %d", item.title, item.rating);
}
void TestList()
{
  List list;
  InitializeList(&list);
  int count = ListItemCount(&list);
  printf("list has %d item(s)\n", count);
  Item item;
  strcpy(item.title, "good film");
  item.rating = 79;
  printf("add an item into list\n");
  AddItem(item, &list);
  count = ListItemCount(&list);
  printf("list has %d item(s)\n", count);
  Traverse(&list, &p);
}