#include "OddDegrees.h"
#include <iostream>
using namespace std;

int* OddDegrees(int** arr, int n)
{
    //variables and allocates an array of the size of vertices
    int* odds;
    odds = (int*) malloc(n * sizeof(int));
    int nodeCount = 1;
    int count = 0;

    //initilizes array to 0
    for(int i = 0; i < n; i++)
    {
        odds[i] = 0;
    }

    //counts the amount of connections a vertice has
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if (arr[i][j] == 1)
                count++;
        }
        if (count % 2 != 0) // checks to see if vertice has odd degree if so put it in the array to indicate its an odd
        {
            odds[nodeCount] = i;
            nodeCount++;
        }
        count = 0;
    }

    //takes are odd degree array and cuts its size to only the necessary amount and sets index 0 to its size for easy manuevarability
    int* sizedOddDegrees = (int*) malloc(nodeCount * sizeof(int));
    sizedOddDegrees[0] = nodeCount;
    for (int i = 1; i < nodeCount; i++)
    {
        sizedOddDegrees[i] = odds[i];
    }
    cout << "The odd-degree vertices in G: O = { ";
    for(int i = 1; i < nodeCount; i++){
            cout << sizedOddDegrees[i] << " ";
    }
    cout << "}\n";
    return sizedOddDegrees;
}