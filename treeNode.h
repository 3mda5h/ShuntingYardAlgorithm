#ifndef TREE_H
#define TREE_H
#include <iostream>

class treeNode
{
  public:
    treeNode(int value);
  private:
    treeNode* left;
    treeNode* right;
    int value;
};
#endif