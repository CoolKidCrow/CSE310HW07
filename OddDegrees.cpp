#include "OddDegrees.h"
#include <iostream>
using namespace std;

int* OddDegrees(int** arr, int n)
{
    int* oddDegrees = new int(n);
    int nodeCount = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        oddDegrees[i] = 0;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if (arr[i][j] == 1)
                count++;
        }
        if (count % 2 != 0)
        {
            oddDegrees[nodeCount] = i;
            nodeCount++;
        }
        count = 0;
    }
    cout << "The odd-degree vertices in G: O = { ";
    for(int i = 0; i < n; i++){
        if (oddDegrees[i] != 0){
            cout << oddDegrees[i] << " ";
        }
    }
    cout << "}";
    return oddDegrees;
}