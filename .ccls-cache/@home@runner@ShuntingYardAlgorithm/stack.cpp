#include <iostream>
#include "stack.h"

using namespace std;

stack::stack()
{
  queue::Node* head = NULL; //top of the stack
}

void stack::push(queue::Node* &node) //add to top of stack
{
  if(head == NULL)
  {
    head = node;
    return;
  }
  node->previous = head;
  head = node;
  //cout << "new head is now:" << head->value << endl;
}

queue::Node* stack::pop() //remove top of stack
{
  if(head == NULL)
  {
    return NULL; //stack empty
  }
  queue::Node* temp = head;
  temp->previous = NULL;
  head = head->previous;
  return temp;
}

queue::Node* stack::peek()
{
  return head;
}