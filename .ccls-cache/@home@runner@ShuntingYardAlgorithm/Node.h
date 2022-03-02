#ifndef TREE_H
#define TREE_H
#include <iostream>

class Node
{
  public:
    Node(char newValue);
    Node* left;
    Node* right;
    Node* tree;
    char value;
};
#endif