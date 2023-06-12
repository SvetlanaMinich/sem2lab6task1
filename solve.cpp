#include "solve.h"

solve::solve()
{

}
int solve::numL(Node* _node)
{
    if(!_node)
    {
        return 0;
    }
    if(!_node->left&&!_node->right)
    {
        return 1;
    }
    return numL(_node->left)+numL(_node->right);
}
