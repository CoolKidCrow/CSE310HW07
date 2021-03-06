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

    //allocates space for a 2d matrix and initilizes it to 0
    arr = new int*[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            arr[i][j] = 0;
        }
    }
    //takes the input and puts it in the 2d matrix
    for(int i = 0; i < m; i++){
        cin >> row >> col;
        arr[row][col] = 1;
        arr[col][row] = 1;
    }


    //calls are various functions that all work to a passable degree :)
    int* oDegrees = OddDegrees(arr, n);
    int** floydWarshall = FloydWarshall(arr, oDegrees, n);
    Edge* matching = GreedyMatch(floydWarshall, oDegrees);
    EulerianCircuit(arr, matching, n, m);

    return 0;
}
