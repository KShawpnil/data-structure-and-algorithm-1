#include <stdio.h>
#include<stdlib.h>
#include "queue.c"
#define CAPACITY 100
#define SUCCESS_VAL 99999
#define FAIL_VAL -99999

int adjMatrix[CAPACITY][CAPACITY];

int n_vertices=0;

void initAdjMatrix(int n){
    // Initialise all value to this
    // Adjacency list to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    n_vertices=n;
}

int addEdge(int i, int j, int w){

    if(i>=n_vertices || j>=n_vertices){
        printf("Invalid vertices\n");
        return FAIL_VAL;
    }
    adjMatrix[i][j]=w;
    return SUCCESS_VAL;
}

int hasEdge(int i, int j){

    if(i>=n_vertices || j>=n_vertices){
        printf("Invalid vertices\n");
        return FAIL_VAL;
    }
    if(adjMatrix[i][j]){
        printf("edge exists from node %d to %d\n",i,j);
        return 1;
    }
    else{
        printf("No edge exists from node %d to %d\n", i, j);
        return 0;
    }
}

int removeEdge(int i, int j){

  if(hasEdge(i,j)!=1){
        printf("Edge doesn't exist\n");
        return FAIL_VAL;
    }
    adjMatrix[i][j]=0;
    return SUCCESS_VAL;
}

int getDegree(int i){

    if(i>=n_vertices){
        printf("Invalid vertices\n");
        return FAIL_VAL;
    }
    int d=0;
    for (int j= 0; j < n_vertices; j++) {
            if(adjMatrix[i][j])
                d++;
    }
    return d;
}

void dfs_impl(int s, int checkArr[])
{
    int i;
    for(i=0;i<n_vertices;i++){
            if(adjMatrix[s][i] && !checkArr[i]){ //i==d
                //printf("%d ",i);
                checkArr[i]=1;
                dfs_impl(i,checkArr);

            }
    }
}

void dfs(int s)
{
    if(s>=n_vertices){
        printf("Invalid vertex\n");
        return FAIL_VAL;
    }

    int i;
    int checkArr[n_vertices];

    for(i=0;i<n_vertices;i++)
        checkArr[i]=0;

    checkArr[s]=1;
    //printf("%d ", s);

    dfs_impl(s, checkArr);
}

void bfs(int s)
{
    if(s>=n_vertices){
        printf("Invalid vertex\n");
        return FAIL_VAL;
    }
    createQueue(CAPACITY);
    enqueue(s);

    int i;
    int checkArr[n_vertices];

    for(i=0;i<n_vertices;i++)
        checkArr[i]=0;

    checkArr[s]=1;

    while(!isQueueEmpty()){
        int v= dequeue();
        printf("%d ",v);
        for(i=0;i<n_vertices;i++){
            if(adjMatrix[v][i] && !checkArr[i]){
                enqueue(i);
                checkArr[i]=1;
            }
        }
    }
}

int BFShasCycle(int s)
{
    createQueue(CAPACITY);
    enqueue(s);

    int i;
    int checkArr[n_vertices];

    for(i=0;i<n_vertices;i++)
        checkArr[i]=0;

    checkArr[s]=1;

    while(!isQueueEmpty()){
        int v= dequeue();
        for(i=0;i<n_vertices;i++){
            if(adjMatrix[v][i])
            {
                if(checkArr[i] && s==i){
                    printf("Cycle exists!\n");
                    return 1;
                }
                else{
                    enqueue(i);
                    checkArr[i]=1;
                }
            }
        }

    }
    printf("Cycle doesn't exist!\n");
    return 1;
}

int DFShascycle(int s)
{
    if(s>=n_vertices){
        printf("Invalid vertex\n");
        return FAIL_VAL;
    }

    int i;
    int checkArr[n_vertices];

    for(i=0;i<n_vertices;i++)
        checkArr[i]=0;

    checkArr[s]=1;

    for(i=0;i<n_vertices;i++){
            if(adjMatrix[s][i] && !checkArr[i]){
                checkArr[i]=1;
                dfs_impl(i,checkArr);
            }
            else if(checkArr[i] && s==i)
            {
                printf("Cycle exit\n");
                return 1;
            }
    }
    printf("Cycle doesn't exit\n");

}

void wholeCycle()
{
     for(int i=0;i<n_vertices;i++){
        DFShascycle(i);
        //BFShasCycle(i);
     }
}

int findPath(int s, int d)
{
    if(s>=n_vertices){
        printf("Invalid vertex\n");
        return FAIL_VAL;
    }

    int i;
    int checkArr[n_vertices];

    for(i=0;i<n_vertices;i++)
        checkArr[i]=0;

    checkArr[s]=1;

    for(i=0;i<n_vertices;i++){
            if(adjMatrix[s][i] && !checkArr[i]){
                    if(i!=d)
                    {
                        printf("Path %d to %d exits", s,d);
                        return 1;
                    }
                //printf("%d ",i);
                checkArr[i]=1;
                dfs_impl(i,checkArr);
            }
    }
    printf("Path %d to %d doesn't exits", s,d);
}

int findPathWeight(int s, int d)
{
    if(s>=n_vertices){
        printf("Invalid vertex\n");
        return FAIL_VAL;
    }

    int i;
    int checkArr[n_vertices];

    for(i=0;i<n_vertices;i++)
        checkArr[i]=0;

    checkArr[s]=1;

    int sum=0;

    for(i=0;i<n_vertices;i++){
            if(adjMatrix[s][i] && !checkArr[i]){
                    if(i!=d)
                    {
                        printf("\nPath %d to %d exits and\n", s,d);
                        //return 1;
                    }
                checkArr[i]=1;
                dfs_impl(i,checkArr);
            }
            printf("\nPath weight %d\n", adjMatrix[s][i]);
            sum = adjMatrix[s][i] + sum;
    }
    printf("\nPath sum %d\n", sum);
    return 1;

    printf("\nPath %d to %d doesn't exits\n", s,d);
}

void printAdjMatrix()
{
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

// Driver Code
int main()
{
    initAdjMatrix(4);

    /*addEdge(0,1 , 6);
    addEdge(0,2 , 4);
    addEdge(1,4 , 4);
    addEdge(2,3 , 5);
    addEdge(4,0 , 3);
    addEdge(4,2 , 6);
    addEdge(3,4 , 5);

    printAdjMatrix();

    dfs(2);*/

//    addEdge(0,1 , 6);
//    addEdge(0,2 , 4);
//    addEdge(1,2 , 4);
//    addEdge(1,3 , 5);
//    addEdge(2,0 , 3);
//    addEdge(3,3, 5);

    addEdge(0,1 , 6);
    addEdge(0,3 , 4);
    addEdge(1,2 , 4);
    addEdge(2,3 , 5);
    addEdge(2,0, 5);

    printAdjMatrix();
    //DFShascycle(2);
    //BFShasCycle(0);
    //wholeCycle();
    //findPath(1,3);
    //findPathWeight(0,2);

}
