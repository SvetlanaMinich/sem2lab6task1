#include "avltree.h"

AVLTree::AVLTree()
{
    root = nullptr;
}
AVLTree::Node::Node()
{
    key=0;
    value="";
    left=nullptr;
    right=nullptr;
}
AVLTree::Node::Node(int _key, QString _value)
{
    key=_key;
    value=_value;
    left=nullptr;
    right=nullptr;
}
int AVLTree::getHeight(Node* _node)
{
    if(!_node)
    {
        return 0;
    }
    return std::max(getHeight(_node->left),getHeight(_node->right))+1;
}
AVLTree::Node* AVLTree::rightRotate(Node* _node)
{
    Node* x = _node->left;
    Node* y = x->right;
    x->right=_node;
    _node->left=y;
    return x;
}
AVLTree::Node* AVLTree::leftRotate(Node* _node)
{
    Node* x = _node->right;
    Node* y = x->left;
    x->left=_node;
    _node->right=y;
    return x;
}
int AVLTree::getBalance(Node* _node)
{
    if(!_node)
    {
        return 0;
    }
    return getHeight(_node->left)-getHeight(_node->right);
}
AVLTree::Node* AVLTree::balance(Node* _node)
{
    int leftH = getHeight(_node->left);
    int rightH = getHeight(_node->right);
    if(leftH-rightH>1)
    {
        if(getHeight(_node->left->left)>=getHeight(_node->left->right))
        {
            _node=rightRotate(_node->left);
        }
        else
        {
            _node->left=leftRotate(_node->left);
            _node=rightRotate(_node);
        }
    }
    else if(rightH-leftH>1)
    {
        if(getHeight(_node->right->right)>=getHeight(_node->right->left))
        {
            _node=leftRotate(_node);
        }
        else
        {
            _node->right=rightRotate(_node->right);
            _node=leftRotate(_node);
        }
    }
    return _node;
}
AVLTree::Node* AVLTree::insert(Node* _node, int _key, QString _value)
{
    if(!_node)
    {
        _node = new Node(_key,_value);
        return _node;
    }
    if(_key<_node->key)
    {
        _node->left=insert(_node->left,_key,_value);
    }
    else if(_key>_node->key)
    {
        _node->right=insert(_node->right,_key,_value);
    }
    else
    {
        //одинаковые ключи не допускаются
        return _node;
    }
    _node=balance(_node);
    return _node;
}
AVLTree::Node* AVLTree::minValueNode(Node* _node)
{
    while(!_node->left)
    {
        _node = _node->left;
    }
    return _node;
}
AVLTree::Node* AVLTree::maxValueNode(Node* _node)
{
    while(!_node->right)
    {
        _node=_node->right;
    }
    return _node;
}
AVLTree::Node* AVLTree::deleteNode(Node* _node, int _key)
{
    if(!_node)
    {
        return _node;
    }
    if(_key<_node->key)
    {
        _node->left=deleteNode(_node->left,_key);
        _node=balance(_node);
    }
    else if(_key>_node->key)
    {
        _node->right=deleteNode(_node->right,_key);
        _node=balance(_node);
    }
    else
    {
        if(!_node->left && !_node->right)
        {
            delete _node;
            _node=nullptr;
        }
        else if(!_node->left)
        {
            Node* x = _node;
            _node=_node->right;
            delete x;
        }
        else if(!_node->right)
        {
            Node* x = _node;
            _node=_node->left;
            delete x;
        }
        else
        {
            Node* x = maxValueNode(_node->left);
            _node->key=x->key;
            _node->value=x->value;
            _node->left=deleteNode(_node->left,x->key);
            _node = balance(_node);
        }
    }
    return _node;
}
void AVLTree::insert(int _key, QString _value)
{
    insert(root,_key,_value);
}
void AVLTree::remove(int _key)
{
    deleteNode(root,_key);
    root = balance(root);
}
QString& AVLTree::operator[](int _key)
{
    Node* curr = root;
    while(curr)
    {
        if(_key>curr->key)
        {
            curr = curr->right;
        }
        else if(_key<curr->key)
        {
            curr=curr->left;
        }
        else
        {
            return curr->value;
        }
    }
    insert(root,_key,"");
    return operator[](_key);
}

















