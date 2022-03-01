#ifndef TREE_H
#define TREE_H
#include <iostream>

class treeNode
{
  public:
    treeNode(char value);
  private:
    treeNode* left;
    treeNode* right;
    char value;
};
#endif