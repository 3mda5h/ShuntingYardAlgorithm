#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
  Node* head = NULL; //right end of the stack
}

void Stack::push(Node* &node) //add to right end of stack
{
  if(head == NULL)
  {
    head = node;
    return;
  }
  node->left = head;
  head = node;
}

Node* Stack::pop() //remove from right end of stack
{
  if(head == NULL)
  {
    return NULL; //stack empty
  }
  Node* temp = head;
  head = head->left;
  temp->left = NULL;
  return temp;
}

Node* Stack::peek()
{
  return head;
}