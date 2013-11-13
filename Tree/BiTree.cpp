#include <cstdlib>
#include <ctime>

#include "BiTree.h"
#include <iostream>

using namespace std;

void InitTreeNode(BiTreeNode** node, int key)
{
  BiTreeNode* tempNode;
  tempNode =(BiTreeNode*)malloc(sizeof(BiTreeNode));
  tempNode->data = key;
  tempNode->lChild = NULL;
  tempNode->rChild = NULL;
  *node = tempNode;
}

void TraverseBiTree(BiTree biTree)
{
  if(biTree == NULL) {
    cout << "Tree is NULL! " << endl;
    return;
  }
  TraverseBiTree(biTree->lChild);
  cout << biTree->data << " ";
  TraverseBiTree(biTree->rChild);
}

void ConstructBiTree(BiTree* biTree, int nodeNumber)
{
  int key;

  srand(time(0));
  for(int i = 0; i < nodeNumber; ++i) {
    key = rand()%NODE_MAX + 1;
    InsertNode(biTree, key);
  }
}

bool InsertNode(BiTree* biTree, int key)
{
  BiTreeNode* tempNode;
  BiTree pNode;
  tempNode = NULL;
  pNode = NULL;

  if (*biTree == NULL) {
    InitTreeNode(&tempNode, key);
    cout << "New ROOT Node: " << key << endl;
    *biTree = tempNode;
    return true;
  }

  if (SearchBiTree(*biTree, key, &pNode, &tempNode)) {
    cout << "Oops! ..Node " << tempNode->data << "already exists!" << endl;
    return false;
  }
  BiTreeNode* tempNode2;
  InitTreeNode(&tempNode2, key);
  if (key > tempNode->data) {
    tempNode->rChild = tempNode2;
  }
  else {
    tempNode->lChild = tempNode2;
  }

  return true;
}

bool DeleteNode(BiTree* biTree, int node)
{
  if (*biTree == NULL) {
    cout << "Node " << node << " doesn't exists, Delete failed!" << endl;
    return false;
  }

  if ((*biTree)->data == node) {
    Delete(biTree);
  }
  else if ((*biTree)->data < node) {
    DeleteNode(&(*biTree)->rChild, node);
  }
  else {
    DeleteNode(&(*biTree)->lChild, node);
  }
}

bool Delete(BiTree* biTree)
{
  BiTreeNode* pNode;
  BiTreeNode* preNode;
  if ((*biTree)->rChild == NULL) {
    pNode = *biTree;
    *biTree = (*biTree)->lChild;
    free(pNode);
  }
  else if ((*biTree)->lChild == NULL) {
    pNode = *biTree;
    *biTree = (*biTree)->rChild;
    free(pNode);
  }
  else{
    pNode = *biTree;
    preNode = (*biTree)->lChild;
    while (preNode->rChild){
      pNode = preNode;
      preNode = preNode->rChild;
    }

    (*biTree)->data = preNode->data;
    if (pNode != *biTree)
      pNode->rChild = preNode->lChild;
    else
      pNode->lChild = preNode->lChild;
    free(preNode);
  }

  return true;
}

bool SearchBiTree(BiTree biTree, int key, BiTree* parentNode, BiTreeNode** treeNode)
{
  cout << "Search Node: " << key << endl;
  if (biTree == NULL) {
    cout << "Found no Node: " << key << endl;
    if ((*parentNode) != NULL)
      cout << "Here is its parent Node " << (*parentNode)->data << endl;
    *treeNode = *parentNode;
    return false;
  }

  if (key == biTree->data) {
    *treeNode = biTree;
    return true;
  }
  else if (key < biTree->data) {
    *parentNode = biTree;
    return SearchBiTree(biTree->lChild, key, &biTree, treeNode);
  }
  else {
    *parentNode = biTree;
    return SearchBiTree(biTree->rChild, key, &biTree, treeNode);
  }
}
