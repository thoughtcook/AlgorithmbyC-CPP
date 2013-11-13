#include <iostream>
#include <cstdlib>
#define MAXVEX 4
using namespace std;

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode{
  int adjvex;
  EdgeType weight;
  struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
  VertexType data;
  EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct{
  AdjList adjList;
  int numVertexes, numEdges;
}GraphAdjList;

void CreateAGraph(GraphAdjList *graph)
{
  cout << "Please input the Graph Vertex number: ";
  cin >> graph->numVertexes;
  cout << "Please input the Graph Edges number: ";
  cin >> graph->numEdges;

  cout << "Now, Please tell me what each vertex node is: ";
  for (int i = 0; i < graph->numVertexes; i++) {
    cout << "Vertex Node " << i << ": ";
    cin >> graph->adjList[i].data;
    graph->adjList[i].firstedge = NULL;
  }

  for(int k = 0; k < graph->numEdges; k++) {
    int i, j;
    EdgeNode* e;
    cout << "Please input the Vertex number of (Vi, Vj)," << endl;
    cout << "Vi: (from 0-3): ";
    cin >> i;
    while (i < 0 || i > graph->numVertexes) {
      cout << "Please input a number between 0 and " << graph->numVertexes - 1 << ": ";
      cin >> i;
    }
    cout << "Vj: (from 0-3): ";
    cin >> j;
    while (j < 0 || j > graph->numVertexes || j == i) {
      cout << "Please input a number between 0 and " << graph->numVertexes - 1 << ": ";
      cin >> j;
    }
    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->next = graph->adjList[i].firstedge;
    graph->adjList[i].firstedge = e;

    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->next =  graph->adjList[j].firstedge;
    graph->adjList[j].firstedge = e;
  }
}

void PrintGraph(GraphAdjList *graph)
{
  cout << "...graph has " << graph->numVertexes << "Vertexes, They are: " << endl;
  for (int i = 0; i < graph->numVertexes; i++) {
    cout << graph->adjList[i].data;
  }
  cout << ">>>graph has " << graph->numEdges << " Edges, They are: " << endl;

  for(int i = 0; i < graph->numVertexes; i++) {
    EdgeNode *e;
    cout << graph->adjList[i].data << ": ";
    for (e = graph->adjList[i].firstedge; e != NULL; e = e->next) {
      cout << (graph->adjList[e->adjvex]).data << "->";
    }
    cout << endl;
  }
}

int main()
{
  GraphAdjList graph;
  CreateAGraph(&graph);
  PrintGraph(&graph);
  return 0;
}
