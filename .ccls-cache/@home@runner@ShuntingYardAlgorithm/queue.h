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
    Node* dequeue();
  private:
    Node* rear;
    Node* front;
}
#endif