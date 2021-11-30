#include <iostream>
#include "OddDegrees.h"
#include "FloydWarshall.h"
#include "GreedyMatch.h"
using namespace std;

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
    int* matching = GreedyMatch(floydWarshall, oddDegrees);


    //for(int i = 0; i <= n;i++) {
    //    delete[] arr[i];
    //}
    //for(int i = 0; i <= n;i++) {
    //    delete[] floydWarshall[i];
    //}
    //delete[] arr;
    //delete[] floydWarshall;
    return 0;
}
