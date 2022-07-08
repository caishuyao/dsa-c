#ifndef _TREE_H_
#define _TREE_H_


typedef int Data;
typedef struct  NODE {
Data data;
struct NODE *left;
struct NODE *right;
} Node,*PtrNode;

typedef struct TREE {
Node *root;
Node *parent;
Node *end;
}Tree,*PtrTree;

void InitialiseTree(Tree * tree);
void AddDataIntoTree(Tree * tree,Data data);
void TraversTree(Tree * tree,void (* pfunc)(Data data));


#endif