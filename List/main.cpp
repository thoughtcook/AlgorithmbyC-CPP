#include <iostream>

using namespace std;

typedef char ElemType;

typedef struct Node
{
  ElemType Key;
  struct Node* next;
}Node;

typedef struct Node *LinkList;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
