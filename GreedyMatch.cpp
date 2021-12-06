#include "GreedyMatch.h"
#include <iostream>
using namespace std;

Edge* GreedyMatch(int** floyd, int* odds)
{
    int x = odds[0] - 1; //amount of odd vertices
    int n = (x * x - x)/2; //amount of unique edge pairs in 2d matrix since its undirected we only need half
    Edge* edges = NULL; //list of pairs of vertices that create an edge
    edges = (Edge*) malloc(sizeof(Edge) * n);

    //converts the 2d matrix into a list of edge pairs
    int index = 0;
    for(int i = 1; i < odds[0]; i++){
        for(int j = 1; j < odds[0]; j++){
            if(i != j && j > i){
                edges[index].x1 = floyd[i][0];
                edges[index].x2 = floyd[0][j];
                edges[index].weight = floyd[i][j];
                edges[index].isVirtual = true;
                index++;
            }
        }
    }

    //sorts edges array using insertion to maintain lexicographical order and because inefficiency is the key to success in life
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j > 0 && edges[j-1].weight > edges[j].weight){
            swap(edges[j], edges[j-1]);
            j--;
        }
    }

    //checks the value of the pairs in perfect match to the value of pairs in edges for one that doesn't
    // match with lowest weight and if no match is found adds it to perfect match
    int pIndex = 1;
    Edge* perfectMatch = NULL;
    perfectMatch = (Edge*) malloc(sizeof(Edge) * ((x / 2) + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (x / 2); j++){
            if(edges[i].x1 == perfectMatch[j].x1 || edges[i].x1 == perfectMatch[j].x2 || edges[i].x2 == perfectMatch[j].x1 || edges[i].x2 == perfectMatch[j].x2){
                break;
            }else{
                if(j == (x / 2) - 1){
                    perfectMatch[pIndex] = edges[i];
                    pIndex++;
                }
            }
        }
    }

    //sets index 0 weight to the amount of pairs in perfectMatch to make it easier to iterate through later
    perfectMatch[0].weight = (x / 2);

    cout << "\nThe greedy perfect matching in O: M = { ";
    for(int i = 1; i <= perfectMatch[0].weight; i++){
        cout << "(" << perfectMatch[i].x1 << "," << perfectMatch[i].x2 << ") ";
    }
    cout << "}\n";


    return  perfectMatch;
}