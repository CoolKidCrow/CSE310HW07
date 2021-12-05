#ifndef CSE310HW07_STACK_H
#define CSE310HW07_STACK_H
#include "Util.h"

class Stack {
private:
    Edge* elements;
    int eSize;
public:
    Stack();
    Stack(int);
    void push(Edge);
    Edge pop();
    Edge peek();
    int size();
};

#endif //CSE310HW07_STACK_H
