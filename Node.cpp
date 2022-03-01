#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(char newValue)
{
  value = newValue;
  left = NULL;
  right = NULL;
}