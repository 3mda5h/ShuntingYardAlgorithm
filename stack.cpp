#include <iostream>
#include "stack.h"

stack::stack()
{
  stack::Node* head = NULL; //top of the stack
}

void stack::push(Node* &node) //add to top of stack
{
  if(head == NULL)
  {
    head = node;
    return;
  }  
  node->previous = head;
  head = node;
}

stack::Node* stack::pop() //remove top of stack
{
  if(head == NULL)
  {
    return NULL; //stack empty
  }
  Node* temp = head;
  temp->previous = NULL;
  head = head->previous;
  return temp;
}

stack::Node* stack::peek()
{
  return head;
}