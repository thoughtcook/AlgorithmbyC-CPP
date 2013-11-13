#include <iostream>
#include "BiTree.h"

#define TREE_NODE_NUMBER 10

using namespace std;

int main()
{
  BiTree myBiTree;
  int node;
  myBiTree = NULL;

  ConstructBiTree(&myBiTree, TREE_NODE_NUMBER);
  TraverseBiTree(myBiTree);

  cout << "Please input the node you want delete: ";
  cin >> node;
  DeleteNode(&myBiTree, node);
  TraverseBiTree(myBiTree);
  return 0;
}
