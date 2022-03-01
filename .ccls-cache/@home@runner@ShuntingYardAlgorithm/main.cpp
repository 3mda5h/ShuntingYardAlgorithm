//shunting yard algorithm - convert infix to postfix
//binary tree - convert postfix to infix or prefix
//2/17/22
#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
#include "treeNode.h"
#include <map>

using namespace std;
char* shuntingyard(char* expression);
void expressionTree(char* conversion, char* expression);
int precedence(char c);

int main()
{
  char input[100];
  char* postfix;
  while(strcmp(input, "quit") != 0)
  {
    cout << "Enter an expression in infix notation" << endl;
    cin.getline(input, 100);
    postfix = shuntingyard(input);
    cout << "postfix: " << postfix << endl;
    while(strcmp(input, "infix") != 0 && strcmp(input, "prefix") != 0 && strcmp(input, "postfix") != 0)
    {
      cout << "Would you like to output infix, prefix, postfix?" << endl;
      cin.getline(input, 100);
      expressionTree(input, postfix);  
    }
  }
}

char* shuntingyard(char* expression)
{
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
        while(operators->peek() != NULL && o2 != '(' && ((precedence(o2) > precedence(o1)) || (precedence(o2) == precedence(o1) && o1 != '^'))) //"^" is only non-left alined operator we have to deal with
        {
          //pop o2 and enqueue it to output
          output->enqueue(operators->pop());
          if(operators->peek() != NULL)
          {
            o2 = operators->peek()->value; 
          }
        }
      }
      //(3*4)^(8*9)
      //enqueue operator 
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
      while(operators->peek() != NULL && operators->peek()->value != '(')
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
  char* outputc = new char[100];
  //add everything in output queue to output char[]
  int i = 0;
  while(output->front != NULL)
  {
    outputc[i] = output->dequeue()->value;
    i++;
  }
  return outputc;
}

//3+4/2+(3-4)^8
//returns precedence given an operator
//could have done with a map but it wasn't working?
int precedence(char c)
{
  if(c == '^') return 4;
  if(c == '/') return 3;
  if(c == '*') return 3;
  if(c == '-') return 2;
  if(c == '+') return 2;
  return 0;
}

void expressionTree(char* conversion, char* expression)
{
  stack* treeStack = new stack();
  for(int i = 0; i < strlen(expression); i++)
  {
    if(isdigit(expression[i]) == true)
    {
      treeNode* root = new treeNode(expression[0]);
      treeStack->push(root);
    }
    if(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*' || expression[i] == '^')
    {
      
    }
  }  
}

  

