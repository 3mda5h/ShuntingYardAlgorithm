#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
  Node* head = NULL; //top of the stack
}

void Stack::push(Node* &node) //add to top of stack
{
  if(head == NULL)
  {
    head = node;
    return;
  }
  node->left = head; //left = previous
  head = node;
  //cout << "new head is now:" << head->value << endl;
}

Node* Stack::pop() //remove top of stack
{
  if(head == NULL)
  {
    return NULL; //stack empty
  }
  Node* temp = head;
  temp->left = NULL;
  head = head->left;
  return temp;
}

Node* Stack::peek()
{
  return head;
}