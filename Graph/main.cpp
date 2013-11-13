#include <iostream>

using namespace std;

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 100
#define INFINITY 65535

typedef struct
{
  VertexType Vexs[MAXVEX];
  EdgeType Arc[MAXVEX][MAXVEX];
  int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
  int i, j, k, w;
  cout << "Please Input the Vertex number: " << endl;
  cin >> G->numVertexes;
  cout << "Please Input the Edge number: " << endl;
  cin >> G->numEdges;
  for (i = 0; i < G->numVertexes; i++) {
    cout << "Please input every Vertex's name " << i << ": ";
    cin >> G->Vexs[i];
  }
  for (i = 0; i < G->numVertexes; i++) {
    for (j = 0; j < G->numVertexes; j++) {
      G->Arc[i][j]  = INFINITY;
    }
  }

  for(k = 0; k < G->numEdges; k++) {
    cout << "Edge " << k << ": " << endl;
    cout << "Vi: ";
    cin >> i;
    while (i < 0 || i >= G->numVertexes) {
      cout << "Please input a number between 0 and " << G->numVertexes - 1 << ": ";
      cin >> i;
    }
    cout << " Vj: ";
    cin >> j;
    while (j < 0 || j >= G->numVertexes || j == i) {
      cout << "Please input a number between 0 and " << G->numVertexes - 1;
      cout << " and NOT equal with " << i << ": ";
      cin >> j;
    }
    cout << " weight: ";
    cin >> w;
    G->Arc[i][j] = G->Arc[j][i] = w;
  }
}

void PrintGraph(MGraph *G)
{
  cout << "Graph Vertexes: ";
  for (int i = 0; i < G->numVertexes; i++) {
    cout << G->Vexs[i] << " ";
  }
  cout << endl;

  cout << "Graph Edges:" << endl;
  for (int i = 0; i < G->numVertexes; i++) {
    for (int j = 0; j < G->numVertexes; j++) {
      cout << G->Arc[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  MGraph Graph;
  CreateMGraph(&Graph);
  PrintGraph(&Graph);
  return 0;
}
