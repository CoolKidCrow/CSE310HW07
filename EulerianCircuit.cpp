#include "EulerianCircuit.h"
#include <iostream>
#include "Stack.h"
#include "FloydWarshall.h"
using namespace std;

int** adjMatrix;
int** virtualMatrix;
bool* visited;
Stack* stack;
Edge* circuit;
int index = 0;


void EulerianCircuit(int** arr, Edge* matching, int n, int m)
{
    adjMatrix = new int*[n+1];
    for(int i = 0; i <= n; i++){
        adjMatrix[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adjMatrix[i][j] = arr[i][j];
        }
    }

    visited = new bool [n];
    for(int i = 1; i <= n; i++){
        visited[i] = false;
    }
    stack = new Stack(m * 2);

    virtualMatrix = new int*[n+1];
    circuit = (Edge*) malloc(sizeof(Edge) * (2 * m));

    for(int i = 0; i <= n; i++){
        virtualMatrix[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            virtualMatrix[i][j] = 0;
        }
    }
    for(int i = 1; i <= matching[0].weight; i++){
        virtualMatrix[matching[i].x1][matching[i].x2] = matching[i].weight;
        virtualMatrix[matching[i].x2][matching[i].x1] = matching[i].weight;
    }

    DFS(1, n);

    cout << "\nThe Euler circuit in G with virtual edges is:\n";
    for(int i = 0; i < index; i++){
        if (circuit[i].isVirtual){
            RecoverPath(arr, n, circuit[i]);
        }else{
            cout << "(" << circuit[i].x1 << "," << circuit[i].x2 << ")\n";
        }
    }
}

void DFS(int vertex, int n)
{
    for(int i = 1; i <= n; i++){
        if(adjMatrix[vertex][i] != 0)
        {
                struct Edge edge = {vertex, i, adjMatrix[vertex][i], false};
                stack->push(edge);
                adjMatrix[vertex][i] = 0;
                adjMatrix[i][vertex] = 0;
                DFS(i, n);
        }
        if(virtualMatrix[vertex][i] != 0)
        {
            struct Edge edge = {vertex, i, virtualMatrix[vertex][i], true};
            stack->push(edge);
            virtualMatrix[vertex][i] = 0;
            virtualMatrix[i][vertex] = 0;
            DFS(i, n);
        }
    }
    if (stack->size() > 0){
        Edge pop = stack->pop();
        circuit[index] = pop;
        circuit[index].x1 = pop.x2;
        circuit[index].x2 = pop.x1;
        index++;
    }
}
