#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


void InitialiseTree(Tree * tree){
  tree->root = (PtrNode) malloc(sizeof(PtrNode));
  tree->parent=NULL;
}

void AddDataIntoTree(Tree * tree,Data  data){
  
}
void TraversTree(Tree * tree,void (* pfunc)(Data data)){

}