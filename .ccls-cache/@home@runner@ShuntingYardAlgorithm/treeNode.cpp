#include <iostream>
#include "treeNode.h"

using namespace std;

treeNode::treeNode(char newValue)
{
  value = newValue;
  left = NULL;
  right = NULL;
}