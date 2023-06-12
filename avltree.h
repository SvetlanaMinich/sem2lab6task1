#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <QString>

class AVLTree
{
public:
    struct Node
    {
        int key;
        QString value;
        Node* left;
        Node* right;
        Node();
        Node(int _key, QString _value);
    };
    AVLTree();
    int getHeight(Node* _node);
    Node* rightRotate(Node* _node);
    Node* leftRotate(Node* _node);
    int getBalance(Node* _node);
    Node* balance(Node* _node);
    Node* insert(Node* _node, int _key, QString _value);
    Node* minValueNode(Node* _node);
    Node* maxValueNode(Node* _node);
    Node* deleteNode(Node* _root, int _key);

    QString& operator[](int _key);
    void insert(int _key, QString _value);
    void remove(int _key);
private:
    Node* root;
};

#endif // AVLTREE_H
