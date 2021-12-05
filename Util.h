#ifndef CSE310HW07_UTIL_H
#define CSE310HW07_UTIL_H

struct Edge {
    int x1 = 0, x2 = 0;
    int weight = 0;
    bool isVirtual = false;
};

struct Vertex {
    int val = 0;
    bool visited = true;
};

#endif //CSE310HW07_UTIL_H
