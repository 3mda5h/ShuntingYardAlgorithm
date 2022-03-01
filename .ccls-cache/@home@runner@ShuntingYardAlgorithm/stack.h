#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "queue.h"

class stack
{ 
  public:
    stack();
    void push(queue::Node* &node);
    queue::Node* pop();
    queue::Node* peek();
    queue::Node* head;
};
#endif