#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(char newValue)
{
  value = newValue; //operator/operand
  left = NULL;
  right = NULL;
  tree = NULL; //used for expression tree but not for shunting yard
}