#ifndef STACK_H
#define STACK_H

#include <iostream>

class stack
{ 
  public:
   struct Node
    {
      char value;
      Node* previous = NULL;
    };
    stack();
    void push(Node* &node);
    stack::Node* pop();
    stack::Node* peek();
    stack::Node* head;
};
#endif