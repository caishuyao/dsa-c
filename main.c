#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main(){
  Tree * tree = (Tree * )malloc(sizeof(Tree));
  Data data=10;
  InitialiseTree(tree);
  AddDataIntoTree(tree,data);
  return 0;
}