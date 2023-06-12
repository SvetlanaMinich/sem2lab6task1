#ifndef SOLVE_H
#define SOLVE_H
#include "avltree.h"

class solve:public AVLTree
{
public:
    solve();
    int numL(Node* _node);
};

#endif // SOLVE_H
