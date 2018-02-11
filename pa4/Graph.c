/*
  Name:Thomas Pham
  CruzID: tpham26
  Pa4
*/

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"
//#include "List.h"

typedef struct GraphObj{
  /*
  adjList -
    each row is the vertex
    the contents of the row are the edge connections
  */
  List *adjList;
  int *colors; // 0 = white, 1  = gray, -1 = black
  int *parents;
  int *distance;

  int order; // number of vertices
  int size; // number of edges
  int src; // vertex that was most recently used for BFS
} GraphObj;


Graph newGraph(int n){
  Graph G;
  // allocating memory for the Graph
  G = malloc (sizeof(GraphObj));
  G->adjList = malloc( (n + 1) * sizeof(List));
  G->colors = malloc( (n + 1) * sizeof(int));
  G->parents = malloc( (n + 1) * sizeof(int));
  G->distance = malloc( (n + 1) * sizeof(int));


  //Setting values of everything
  for(int i = 1; i < n + 1; i++){
    G->adjList[i] = newList();
    G->colors[i] = WHITE;
    G->parents[i] = NIL;
    G->distance[i] = INF;
  }

  G->order = n;
  G->size = 0;
  G->src = NIL;

  return G;
}


void freeGraph(Graph *pG){
  for(int i = 1; i < (*pG)->order + 1; i++){
    freeList(&(*pG)->adjList[i]);
  }
  free((*pG)->adjList);
  free((*pG)->colors);
  free((*pG)->parents);
  free((*pG)->distance);
  free(*pG);
  *pG = NULL;
}

int getOrder(Graph G){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  return G->order;
}

int getSize(Graph G){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  return G->size;
}

int getSource(Graph G){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  return G->src;
}

int getParent(Graph G, int u){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  return G->parents[u];
}

int getDist(Graph G, int u){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  return G->distance[u];
}

void getPath(List L, Graph G, int u){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  if(G->colors[u] != BLACK){
    append(L, NIL);
    return;
  }
  if(G->parents[u] == NIL){
    append(L,u);
    return;
  }
  getPath(L, G, G->parents[u]);
  append(L,u);
}

void makeNull(Graph G){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  for(int i = 0; i < G->order; i++){
    clear(G->adjList[i]);
  }
  G->size = 0;
}

void insertInList(List l, int v){
  if(length(l) == 0){
    append(l,v);
    return;
  }

  moveFront(l);
  while( index(l) != -1){
     if(get(l) > v) { // current element is bigger than v
       insertBefore(l, v);
       break;
     }
    moveNext(l);
  }

  //now at the end of the list, so just append v
  if(index(l) == -1){
    append(l, v);
  }

}

// vertex u has a connection with vertex v
void addEdge(Graph G, int u, int v){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  //do insertion at the right place
  insertInList(G->adjList[u], v); // inserting v into row u
  insertInList(G->adjList[v], u); // inserting u into row v
  G->size++;
}

void addArc(Graph G, int u, int v){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  insertInList(G->adjList[u], v);
  G->size++;
}

void BFS(Graph G, int s){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  //making sure all atributes are set to first values;
  for(int i = 1; i <= getOrder(G); i++){
    G->colors[i] = WHITE;
    G->distance[i] = INF;
    G->parents[i] = NIL;
  }
  G->src = s;
  G->colors[s] = GRAY;
  G->distance[s] = 0;
  G->parents[s] = NIL;
  List q = newList();
  append(q, s);

  //Going through the entire queue
  while(length(q) != 0){
    int x = dequeue(q);
    moveFront(G->adjList[x]);

    for(int i = 0; i < length(G->adjList[x]); i++){
        int y = get(G->adjList[x]);
        if(G->colors[y] == WHITE){
          G->colors[y] = GRAY;
          G->distance[y] = G->distance[x] + 1;
          G->parents[y] = x;
          append(q,y);
        }
        moveNext(G->adjList[x]);
    }
    G->colors[x] = BLACK;
  }

  freeList(&q);
}

int dequeue(List l){
  moveFront(l);
  int x = get(l);
  deleteFront(l);

  return x;
}

void printGraph(FILE* out, Graph G){
  if(G == NULL){
    printf("G is NULL\n");
    exit(1);
  }
  for(int i = 1; i < getOrder(G) + 1; i++){
    fprintf(out, "%d: ", i);
    printList(out,G->adjList[i]);
    fprintf(out, "\n");
  }
}
