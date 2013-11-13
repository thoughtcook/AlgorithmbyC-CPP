#define NODE_MAX 100

typedef struct BiTreeNode
{
  int data;
  struct BiTreeNode *lChild, *rChild;
}BiTreeNode, *BiTree;

void InitTreeNode(BiTreeNode** node, int key);
void TraverseBiTree(BiTree biTree);
void ConstructBiTree(BiTree* biTree, int nodeNumber);
bool InsertNode(BiTree* biTree, int key);
bool Delete(BiTree* biTree);
bool DeleteNode(BiTree* biTree, int node);
bool SearchBiTree(BiTree biTree, int key, BiTree* parentNode, BiTreeNode** treeNode);
