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
    if(isdigit(expression[i]) == true) //if number add to output queue
    {
      queue::Node* newNode = new queue::Node();
      newNode->value = expression[i];
      output->enqueue(newNode);
    }
    if(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*') //if operator add to operator stack
    {
      stack::Node* newNode = new stack::Node();
      newNode->value = expression[i]
      operators->push(newNode);
    }
  }
  //pop operators off stack and add them to output queue
  stack::Node* current = new stack::Node();
  while(operators->pop() != NULL)
  {
    current = operators->pop(); //remove top of stack
    queue::Node* newNode = new queue::Node();
    newNode->value = current->value; //stupid fix later
    output->enqueue(newNode); //add this to queue
  }
  //print out everything in output queue
  while(output->dequeue() != NULL)
  {
      cout << output->dequeue() << endl;
  }
}

