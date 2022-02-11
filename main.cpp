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

void shuntingyard()
{
  char expression[100];
  cout << "Enter the expression" << endl;
  cin.getline(expression, 100);
  queue* output = new queue();
  stack* operators = new stack();
  for(int i = 0; i < strlen(expression); i++)
  {
    if(isdigit(expression[i]) == true) //if number add to output queue
    {
      queue::Node* newNode = new queue::Node();
      newNode->value = expression[i];
      output->enqueue(newNode);
    }
    if(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*' || expression[i] == '^') //if operator add to operator stack
    {
      stack::Node* newNode = new stack::Node();
      newNode->value = expression[i];
      operators->push(newNode);
    }
  }
  //pop operators off stack and add them to output queue
  char nodeValue;
  while(operators->peek() != NULL)
  {
    nodeValue = operators->pop()->value; //remove top of stack, get its value
    queue::Node* newNode = new queue::Node();
    newNode->value = nodeValue;
    output->enqueue(newNode); //add this to queue
  }
  //print out everything in output queue
  while(output->front != NULL)
  {
    //cout << "hehe" << endl;
    cout << output->dequeue()->value;
  }
}

