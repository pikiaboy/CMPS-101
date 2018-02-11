/*
  Name:Thomas Pham
  CruzID: tpham26
  Pa4
*/



#include "Graph.h"
#include "List.h"

int main(){

  Graph G = new Graph(100);

  addArc(A, 64, 4);
  addArc(A, 64, 3);
  addArc(A, 42, 2);
  addArc(A, 2, 64);
  addArc(A, 4, 2);
  addArc(A, 3, 42);

  printf("Order of G is: %d\n", getOrder(G));
  printf("Size of G is: %d\n", getSize(G));

  BFS(A, 42);

  List L = newList();

  getPath(L,G,2);

  printf("The path from 42 to 2 is: ");
  printList(stdout, L);
  printf("\n");

  printf("The parent of 3 is: %d\n" ,getParent(G,3) );
  printf("The distance from 42 to 3 is: %d", getDist(G,3));

  printf("The Adjacency List of G is: \n");
  printGraph(stdout, G);

  makeNull(G);
  clear(L);

  printf("G is now null: \n");
  printGraph(stdout, G);

  addEdge(A, 64, 4);
  addEdge(A, 64, 3);
  addEdge(A, 42, 2);
  addEdge(A, 2, 64);
  addEdge(A, 4, 2);
  addEdge(A, 3, 42);

  BFS(A, 64);

  getPath(L,G,2);

  printf("The path from 42 to 2 is: ");
  printList(stdout, L);
  printf("\n");

  printf("The parent of 3 is: %d\n" ,getParent(G,3) );
  printf("The distance from 42 to 3 is: %d", getDist(G,3));

  printf("The Adjacency List of G is: \n");
  printGraph(stdout, G);

  freeList(&L);
  freeGraph(&G);
  return 0;
}
