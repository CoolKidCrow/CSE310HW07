#include "OddDegrees.h"
#include <iostream>
using namespace std;

int* OddDegrees(int** arr, int n)
{
    int* oddDegrees;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }


    return oddDegrees;
}