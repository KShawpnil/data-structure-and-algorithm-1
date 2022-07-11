//ID:011201125
//nHour2_Problem2

#include <stdio.h>
#include <stdlib.h>
#define SUCCESS_VAL 99999
#define FAIL_VAL -99999

struct node {
  int vertex;
  int weight;
  struct node* next;
};

int n_vertices=0;

struct node** adjLists;

struct node* createNode(int v, int w){
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}

void initGraph(int n){
  adjLists = malloc(n * sizeof(struct node*));
  int i;
  for (i = 0; i < n; i++)
    adjLists[i] = NULL;
  n_vertices=n;
}

void addEdge(int i, int j, int w){

  struct node* newNode = createNode(j,w);
  newNode->next = adjLists[i];
  adjLists[i] = newNode;
}

int hasEdge(int i, int j){

    struct node* temp = adjLists[i];

    while (temp){
        if(temp->vertex==j){
            //printf("\nEdge exists from node %d to %d\n",i,j);
            return 1;
        }
        temp = temp->next;
    }
    //printf("\nNo edge exists from node %d to %d\n", i, j);
    return 0;
}

//code for problem no 2

int getNeighborsCount(int v)
{
    int Ncount1 = 0;
    int Ncount2 = 0;

    if(v >= n_vertices){
        printf("Invalid Vertices\n");
        return FAIL_VAL;
    }

    for(int j=0; j<n_vertices; j++){
            if(hasEdge(v,j))
                Ncount1++;
    }
    //printf("\nCounting of Outgoing Neighbors from node %d is %d\n", v, Ncount1);

    for(int k=0; k<n_vertices; k++){
            if(hasEdge(k,v))
                Ncount2++;
    }
    //printf("\nCounting of Incoming Neighbors from node %d is %d\n", v, Ncount2);

    int neighbors = Ncount1 + Ncount2;
    printf("\nTotal numbers of outgoing and incoming neighbors from the vertex %d is %d\n", v, neighbors);
}

void printGraph(){

  int v;
  for(v = 0; v < n_vertices; v++){
    struct node* temp = adjLists[v];
    printf("\n%d", v);
    while (temp){
      printf(" -> %d (%d)", temp->vertex, temp->weight);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {

  initGraph(4);

  addEdge(0, 1, 5);
  addEdge(1, 4, 6);
  addEdge(1, 3, 7);
  addEdge(2, 3, 4);
  addEdge(2, 1, 5);
  addEdge(3, 0, 8);
  addEdge(3, 2, 5);

  printGraph();

  getNeighborsCount(3);  //call the function for node 3

  return 0;
}
