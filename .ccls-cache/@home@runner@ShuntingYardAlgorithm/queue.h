#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class queue
{
  public:
  struct Node
    {
      char value;
      Node* previous = NULL;
      Node* next = NULL;
    }; 
    queue();
    void enqueue(Node* node);
    queue::Node* dequeue();
    queue::Node* rear;
    queue::Node* front;
};
#endif