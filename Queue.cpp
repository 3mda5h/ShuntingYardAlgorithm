#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
  Node* rear = NULL;
  Node* front = NULL;
}

void Queue::enqueue(Node* node) //add node to left end of queue
{
  if(rear == NULL) //queue is empty
  {
    rear = node;
    front = node;
    return;
  }
  rear->left = node;
  node->right = rear;
  rear = node;
}

Node* Queue::dequeue() //remove node from right end of queue
{
  if(front == NULL) //queue is empty
  {
    return NULL;
  }
  Node* temp = front;
  if(front->left != NULL) //to avoid seg fault <3
  {
    front = front->left; 
    front->right = NULL;
    return temp;
  }
  front = NULL;
  return temp;
}