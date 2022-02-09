#ifndef STACK_H
#define STACK_H

#include <iostream>

class stack
{
  struct Node
  {
    int value;
    Node* previous = NULL;
  }; 
  public:
    stack();
    void push(Node* &node);
    Node* pop();
    Node* peek();
  private:
    Node* head;
}
#endif