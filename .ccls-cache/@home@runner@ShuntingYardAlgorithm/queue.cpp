#include <iostream>
#include "queue.h"
queue::queue()
{
  queue::Node* rear = NULL;
  queue::Node* front = NULL;
}

void queue::enqueue(Node* node) //add node to end of queue
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

queue::Node* queue::dequeue() //remove node from front of queue
{
  if(front == NULL) //queue is empty
  {
    return NULL;
  }
  Node* temp = front;
  if(front->previous != NULL) //to avoid seg fault *heart face*
  {
    front = front->previous; 
    front->next = NULL;
    return temp;
  }
  front = NULL;
  return temp;
}