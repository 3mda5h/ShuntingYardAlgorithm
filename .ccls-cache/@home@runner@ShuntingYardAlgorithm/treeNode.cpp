#include <iostream>
#include "treeNode.h"

using namespace std;

treeNode::treeNode(int newValue)
{
  value = newValue;
  left = NULL;
  right = NULL;
}