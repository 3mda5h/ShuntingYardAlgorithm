#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

class Stack
{ 
  public:
    Stack();
    void push(Node* &node);
    Node* pop();
    Node* peek();
    Node* head;
};
#endif