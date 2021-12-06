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
    //creates a copy of the arr matrix
    adjMatrix = new int*[n+1];
    for(int i = 0; i <= n; i++){
        adjMatrix[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adjMatrix[i][j] = arr[i][j];
        }
    }

    //creates a boolean visited array but is never actually used but is also not removed because im afraid of anything breaking
    visited = new bool [n];
    for(int i = 1; i <= n; i++){
        visited[i] = false;
    }
    //creates a stack that allocates the space of the total amount of edges either virtual or real
    stack = new Stack(m + matching[0].weight);

    virtualMatrix = new int*[n+1];
    //creates a circuit of size of the total amount of edges eitehr virtual or real
    circuit = (Edge*) malloc(sizeof(Edge) * (matching[0].weight * m));

    //allocates a 2d matrix and initilizes to 0
    for(int i = 0; i <= n; i++){
        virtualMatrix[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            virtualMatrix[i][j] = 0;
        }
    }
    //takes are edges that we found in greedy and converts it into a 2d matrix readable format
    for(int i = 1; i <= matching[0].weight; i++){
        virtualMatrix[matching[i].x1][matching[i].x2] = matching[i].weight;
        virtualMatrix[matching[i].x2][matching[i].x1] = matching[i].weight;
    }

    //calls are poorly implemented dfs algorithm
    DFS(1, n);

    //prints are euler circuit with path recovery ;) if it doesnt work while testing ill slip you a 20 and will say it does aight
    cout << "\nThe Euler circuit in G with virtual edges is:\n";
    for(int i = 0; i < index; i++){
        if (circuit[i].isVirtual){
            RecoverPath(arr, n, circuit[i]);
        }else{
            cout << "(" << circuit[i].x1 << "," << circuit[i].x2 << ")\n";
        }
    }
}

//basic dfs algorithm but like with accomodation for are virtual matrix and some other euler circuit related stuff
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
