#include "FloydWarshall.h"
#include <iostream>
using namespace std;

int** FloydWarshall(int** arr, int* odds, int n)
{
    int** floyd = new int*[n+1];
    for(int i = 0; i <= n; i++){
        floyd[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(arr[i][j] == 1){
                floyd[i][j] = arr[i][j];
            }else{
                floyd[i][j] = INT16_MAX;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        floyd[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    int** floydOdds = new int*[odds[0]];
    for(int i = 0; i < odds[0]; i++){
        floydOdds[i] = new int[odds[0]];
    }
    for(int i = 0; i < odds[0]; i++){
        for(int j = 0; j < odds[0]; j++){
            floydOdds[i][j] = 0;
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int x = 1; x < odds[0]; x++){
                for(int y = 1; y < odds[0]; y++){
                    if(odds[x] == i && odds[y] == j){
                        floydOdds[x][y] = floyd[i][j];
                    }
                }
            }
        }
    }
    for(int i = 1; i < odds[0]; i++){
        floydOdds[0][i] = odds[i];
        floydOdds[i][0] = odds[i];
    }

    cout << "\nResults of Floyd-Warshall on O:\n  ";
    for(int i = 0; i < odds[0]; i++){
        for(int j = 0; j < odds[0]; j++){
            if (!(i == 0 && j == 0))
            {
                cout << floydOdds[i][j] << " ";
            }
        }
        cout << "\n";
    }


    return floydOdds;
}

void RecoverPath(int** arr, int n, Edge edge)
{
    int** floyd = new int*[n+1];
    int** next = new int*[n+1];
    for(int i = 0; i <= n; i++){
        floyd[i] = new int[n+1];
        next[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(arr[i][j] == 1){
                floyd[i][j] = arr[i][j];
                next[i][j] = j;
            }else{
                floyd[i][j] = INT16_MAX;
                next[i][j] = NULL;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        floyd[i][i] = 0;
        next[i][i] = i;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (floyd[i][j] > floyd[i][k] + floyd[k][j]){
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    int* path = new int[n];
    int index = 1;
    int u = edge.x1;
    int v = edge.x2;
    path[0] = u;
    while (u != v)
    {
        u = next[u][v];
        path[index] = u;
        index++;
        path[index] = u;
        index++;
    }
    int counter = 0;
    for(int i = 0; i < index - 1; i++)
    {
        if (counter == 0){
            cout << "(" << path[i] << ",";
            counter++;
        }else{
            cout << path[i] << ")\n";
            counter = 0;
        }
    }

}