#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
#include "treeNode.h"
#include <map>

using namespace std;
void shuntingyard(map<const char*, int>&precedence);

int main()
{
  map<const char*, int>precedence;
  precedence["^"] = 4;
  precedence["*"] = 3;
  precedence["/"] = 3;
  precedence["+"] = 2;
  precedence["-"] = 2;
  //precedence.insert(pair<const char*, const char*>("^", "right"));
  //precedence.insert(pair<const char*, int>("^", 3))

  shuntingyard(precedence);
}

void shuntingyard(map<const char*, int>&precedence)
{
  char expression[100];
  cout << "Enter the expression" << endl;
  cin.getline(expression, 100);
  queue* output = new queue();
  stack* operators = new stack();
  char o1;
  char o2;
  for(int i = 0; i < strlen(expression); i++)
  {
    if(isdigit(expression[i]) == true) //if number add to output queue
    {
      queue::Node* newNode = new queue::Node();
      newNode->value = expression[i];
      output->enqueue(newNode);
    }
    else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*' || expression[i] == '^') //if operator
    {
      o1 = expression[i];
      o2 = operators->peek()->value;
      while(operators->peek()->value != ')' && ((precedence.at(&o2) > precedence.at(&o1)) || (precedence.at(&o2) == precedence.at(&o1) && o1 != '^')))
      {
        output->enqueue(operators->pop());
        
        o2 = operators->peek()->value;
      }
      stack::Node* newNode = new stack::Node();
      newNode->value = expression[i];
      operators->push(newNode);
    }
    else if(expression[i] == '(')
    {
      stack::Node* newNode = new stack::Node();
      newNode->value = expression[i];
      operators->push(newNode);
    }
    else if(expression[i] == ')')
    {
      while(operators->peek()->value != '(' && operators->peek() != NULL)
      {
        
      }
    }
  }
  //pop operators off stack and add them to output queue
  char nodeValue;
  while(operators->peek() != NULL)
  {
    nodeValue = operators->pop()->value; //remove top of stack, get its value
    queue::Node* newNode = new queue::Node(); //new queue node so it doesnt get angry when i try to put it in queue lololol
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

