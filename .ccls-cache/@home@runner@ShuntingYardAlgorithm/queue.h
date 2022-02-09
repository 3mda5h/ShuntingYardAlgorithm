#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class queue
{
  struct Node
  {
    int value;
    Node* previous = NULL;
    Node* next = NULL;
  }; 
  public:
    queue();
    void enqueue(Node* node);
    Node* dequeue();
  private:
    Node* rear;
    Node* front;
}
#endif