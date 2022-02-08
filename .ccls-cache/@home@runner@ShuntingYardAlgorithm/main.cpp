#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node* previous = NULL;
  Node* next = NULL;
};

bool push(Node* &node, Node* &stackHead);
Node* pop(Node* stackHead);

int main()
{
  Node* stackHead = NULL; //head is the top of the stack
}

bool push(Node* &node, Node* &stackHead) //add node to top of stack
{
  if(stackHead == NULL)
  {
    return false; //list empty
  }
  if(node->previous != NULL)
  {
    node->previous = stackHead;
  }
  stackHead = node;
  return true; //list not empty
}

Node* pop(Node* &stackHead)
{
  Node* temp = stackHead;
  stackHead = stackHead->previous;
  return temp;
  delete temp;
}

