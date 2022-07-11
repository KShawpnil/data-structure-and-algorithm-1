#include <stdio.h>
#include<stdlib.h>
#define CAPACITY 100
#define SUCCESS_VAL 99999
#define FAIL_VAL -99999

int adjMatrix[CAPACITY][CAPACITY];

int n_vertices=0;

void initAdjMatrix(int n){

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    n_vertices=n;
}

int addEdge(int i, int j, int w){

    if(i>=n_vertices || j>=n_vertices){
        printf("Invalid Vertices.\n");
        return FAIL_VAL;
    }
    adjMatrix[i][j]=w;
    return SUCCESS_VAL;
}

int hasEdge(int i, int j){

    if(i>=n_vertices || j>=n_vertices){
        printf("Invalid vertice\n");
        return FAIL_VAL;
    }
    if(adjMatrix[i][j]){
        //printf("\nEdge exists from node %d to %d\n",i,j);
        return 1;
    }
    else{
        //printf("\nNo edge exists from node %d to %d\n",i,j);
        return 0;
    }
}

int getNetWeight(int i)
{
    if(i>=n_vertices){
        printf("Invalid Vertices\n");
        return FAIL_VAL;
    }

    int j,k;
    int Osum=0;
    int Isum=0;
    int NetWeight=0;

    for (j=0; j<n_vertices; j++){
            if(hasEdge(i,j)){
           printf("\nOutgoing edge's weight: %d \n", adjMatrix[i][j]);
      }
      Osum = adjMatrix[i][j] + Osum;
    }
    printf("\nOsum = %d\n", Osum);  //get the summation of total outgoing edge's weight

    for (k=0; k<n_vertices; k++){
            if(hasEdge(k,i)){
           printf("\nIncoming edge's weight: %d \n", adjMatrix[k][i]);
        }
        Isum = adjMatrix[k][i] + Isum;
    }
    printf("\nIsum = %d\n", Isum);  //get the summation of total incoming edge's weight

    NetWeight = Osum - Isum;
    printf("\nNetWeight of the vertex %d is = %d\n", i, NetWeight);  //get the NetWeight of both outgoing and incoming edge's weights from the calling vertex
}

void printAdjMatrix(){
    printf("   ");
    for (int i = 0; i < n_vertices; i++) {
        printf("(%d) ", i);
    }
    printf("\n");

    for (int i = 0; i < n_vertices; i++) {
            printf("(%d)",i);
        for (int j = 0; j < n_vertices; j++) {

            // Print the value at Adj[i][j]
            printf(" %d  ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    initAdjMatrix(5);

    addEdge(0,1 , 6);
    addEdge(0,2 , 1);
    addEdge(1,4 , 5);
    addEdge(1,3 , 2);
    addEdge(2,4 , 9);
    addEdge(3,2 , 5);
    addEdge(3,0 , 4);
    addEdge(4,3 , 1);

    printAdjMatrix();

    getNetWeight(3);  //call the function for vertex 3
}
