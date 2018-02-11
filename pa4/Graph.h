/*
  Name:Thomas Pham
  CruzID: tpham26
  Pa4
*/

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_

#define INF -1
#define NIL -2

#define WHITE 0
#define GRAY 1
#define BLACK -1
#include "List.h"

typedef struct GraphObj* Graph;

/*** Constructors-Destructors ***/
Graph newGraph(int n);
void freeGraph(Graph* pG);
/*** Access functions ***/
int getOrder(Graph G); //number of vertices
int getSize(Graph G); // number of edges
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);
/*** Manipulation procedures ***/
void makeNull(Graph G);
void insertInList(List l, int v); // helper function for addEdge and addArc
void addEdge(Graph G, int u, int v); // unidirected edge
void addArc(Graph G, int u, int v); // directed edge
void BFS(Graph G, int s);
int dequeue(List l);
/*** Other operations ***/
void printGraph(FILE* out, Graph G);

#endif
