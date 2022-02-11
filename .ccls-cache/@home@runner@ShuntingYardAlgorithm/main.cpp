#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
#include "treeNode.h"

using namespace std;
void shuntingyard();

int main()
{
  shuntingyard();
}

void shutingyard()
{
  char expression[100];
  cout << "Enter the expression" << endl;
  cin.getline(expression, 100)
  queue* output = new queue();
  stack* operators = new stack();
  for(int i = 0; i < strlen(expression); i++)
  {
    if(isdigit(expression[i]) == true)
    {
      queue::Node* newNode = new queue::Node();
      newNode->value = expression[i];
      output->enqueue(newNode);
    }
    if(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*')
    {
      stack::Node* newNode = new stack::Node();
      newNode->value = expression[i]
      operators =
    }
  }
}

