#ifndef STACK_H
#define STACK_H

#include <iostream>

class stack
{ 
  public:
   struct Node
    {
      int value;
      Node* previous = NULL;
    };
    stack();
    void push(Node* &node);
    Node* pop();
    Node* peek();
  private:
    Node* head;
}
#endif