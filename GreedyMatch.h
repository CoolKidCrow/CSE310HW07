#ifndef CSE310HW07_GREEDYMATCH_H
#define CSE310HW07_GREEDYMATCH_H

struct Edge {
    int x1 = 0, x2 = 0;
    int weight = 0;
};

Edge* GreedyMatch(int**, int*);

#endif //CSE310HW07_GREEDYMATCH_H
