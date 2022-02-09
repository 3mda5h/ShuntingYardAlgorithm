#include <iostream>
#include "queue.h"
queue::queue()
{
  Node* rear = NULL;
  Node* front = NULL;
}

void queue::enqueue(Node* node)
{
  if(rear == NULL) //queue is empty
  {
    rear = node;
    front = node;
    return;
  }
  rear->previous = node;
  node->next = rear;
  rear = node;
}

queue::Node* queue::dequeue()
{
  if(rear == NULL)
  {
    return NULL;
  }
  Node* temp = front;
  front->previous = front;
  front->previous->next = NULL;
  return temp;
}