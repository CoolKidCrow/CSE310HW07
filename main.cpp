#include <iostream>
#include "OddDegrees.h"
#include "FloydWarshall.h"
#include "GreedyMatch.h"
#include "EulerianCircuit.h"
#include "Util.h"
using namespace std;

int z = 0;

int main() {
    int** arr;
    int n, m, row, col;
    cin >> n >> m;

    arr = new int*[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> row >> col;
        arr[row][col] = 1;
        arr[col][row] = 1;
    }


    int* oddDegrees = OddDegrees(arr, n);
    int** floydWarshall = FloydWarshall(arr, oddDegrees, n);
    Edge* matching = GreedyMatch(floydWarshall, oddDegrees);
    EulerianCircuit(arr, matching, n, m);

    return 0;
}
