//shunting yard algorithm - convert infix to postfix
//2/17/22
#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
#include "treeNode.h"
#include <map>

using namespace std;
void shuntingyard();
int precedence(char c);

int main()
{
  /*map<const char*, int>precedence;
  precedence.emplace("^", 4);
  precedence.emplace("/", 3);  
  precedence.emplace("*", 3);
  precedence.emplace("+", 2);
  precedence.emplace("-", 2);

  const char* c = "^";
  cout << precedence.at(c) << endl;*/

  shuntingyard();
}

void shuntingyard()
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
      if(operators->peek() != NULL) //if stack is not empty
      {
        o2 = operators->peek()->value;
        cout << o2 << endl;
      //cout << precedence.at(o2) << endl;
        while(operators->peek() != NULL && o2 != '(' && ((precedence(o2) > precedence(o1)) || (precedence(o2) == precedence(o1) && o1 != '^'))) 
        {
          //pop o2 and enqueue it to output
          output->enqueue(operators->pop());
          o2 = operators->peek()->value;
          //push o1
        }
      }
      queue::Node* newNode = new queue::Node();
      newNode->value = expression[i];
      operators->push(newNode);
    }
    else if(expression[i] == '(')
    {
      //push onto operator stack
      queue::Node* newNode = new queue::Node();
      newNode->value = expression[i];
      operators->push(newNode);
    }
    else if(expression[i] == ')')
    {
      while( operators->peek() != NULL && operators->peek()->value != '(')
      {
        //pop from operators and queue into output
        output->enqueue(operators->pop());
      }
      delete operators->pop(); //discard left parenthesis
    }
  }
  //pop operators off stack and add them to output queue
  while(operators->peek() != NULL)
  {
    output->enqueue(operators->pop()); //add top operator to queue
  }
  //print out everything in output queue
  while(output->front != NULL)
  {
    //cout << "hehe" << endl;
    cout << output->dequeue()->value;
  }
}

int precedence(char c)
{
  if(c == '^') return 4;
  if(c == '/') return 3;
  if(c == '*') return 3;
  if(c == '-') return 2;
  if(c == '+') return 2;
}

  

