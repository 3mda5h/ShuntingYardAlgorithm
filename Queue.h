#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"

class Queue
{
  public:
    Queue();
    void enqueue(Node* node);
    Node* dequeue();
    Node* rear;
    Node* front;
};
#endif