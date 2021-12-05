#include "Stack.h"
#include <iostream>

Stack::Stack(){}

Stack::Stack(int n)
{
    elements = (Edge*) malloc(sizeof(Edge) * n);
    eSize = 0;
}

void Stack::push(Edge edge)
{
    elements[eSize] = edge;
    eSize++;
}

Edge Stack::pop()
{
    eSize--;
    return elements[eSize];
}

Edge Stack::peek()
{
    return elements[eSize - 1];
}

int Stack::size()
{
    return eSize;
}