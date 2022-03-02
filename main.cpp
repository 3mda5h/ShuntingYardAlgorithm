//shunting yard algorithm - convert infix to postfix
//binary tree - traverse tree and output postfix, infix, or prefix
//Emily MacPherson 2/17/22
#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Queue.h"
#include "Node.h"

using namespace std;
char* shuntingyard(char* expression);
int precedence(char c);
void expressionTree(char* conversion, char* expression);
void infixTraversal(Node* tree);
void prefixTraversal(Node* tree);
void postfixTraversal(Node* tree);
bool isOperator(char value);

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
  Queue* output = new Queue();
  Stack* operators = new Stack();
  char o1;
  char o2;
  for(int i = 0; i < strlen(expression); i++)
  {
    if(isdigit(expression[i]) == true) //if number add to output queue
    {
      Node* newNode = new Node(expression[i]);
      output->enqueue(newNode);
    }
    else if(isOperator(expression[i]) == true)
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
      //4^(8*9) - SEG FAULT
      //enqueue operator 
      Node* newNode = new Node(expression[i]);
      operators->push(newNode);
    }
    else if(expression[i] == '(')
    {
      //push onto operator stack
      Node* newNode = new Node(expression[i]);
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

//returns precedence given an operator - could have done with a map but it was being stinky
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
  //create expression tree from postfix expression
  Stack* stack = new Stack();
  for(int i = 0; i < strlen(expression); i++)
  {
    if(isdigit(expression[i]) == true)
    {
      Node* leaf = new Node(expression[i]);
      Node* stackNode = new Node(NULL);
      stackNode->tree = leaf;
      stack->push(stackNode);
    }
    else if(isOperator(expression[i]) == true)
    {
      Node* root = new Node(expression[i]);
      Node* stackNode = new Node(NULL);
      stackNode->tree = root;
      root->right = stack->pop()->tree;
      root->left = stack->pop()->tree;
      stack->push(stackNode);
    }
  }
  Node* tree = stack->pop()->tree;
  
  //traverse tree
  if(strcmp(conversion, "infix") == 0)
  {
    cout << "infix: ";
    infixTraversal(tree);
    cout << endl;
  }
  else if(strcmp(conversion, "prefix") == 0)
  {
    cout << "prefix: ";
    prefixTraversal(tree);
    cout << endl;
  }
  else if(strcmp(conversion, "postfix") == 0)
  {
    cout << "postfix: ";
    postfixTraversal(tree);
    cout << endl;
  }  
}

void infixTraversal(Node* tree)
{
  if(tree != NULL)
  {
    if(isOperator(tree->value) == true)
    {
      cout << "(";
    }
    infixTraversal(tree->left);
    cout << tree->value;
    infixTraversal(tree->right);
    if(isOperator(tree->value))
    {
      cout << ")";
    }
  }
}

void prefixTraversal(Node* tree)
{
  if(tree != NULL)
  {
    cout << tree->value;
    prefixTraversal(tree->left);
    prefixTraversal(tree->right);
  }
}

void postfixTraversal(Node* tree)
{
  if(tree != NULL)
  {
    postfixTraversal(tree->left);
    postfixTraversal(tree->right);
    cout << tree->value;
  }
}

bool isOperator(char value)
{
  if(value == '+' || value == '-' || value == '/' || value == '*' || value == '^')
  {
    return true;
  }
  return false;
}

  

