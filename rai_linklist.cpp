#include "rai_linklist.h"
#include <iostream>

/*

Author: Aryan Rai

Date: 4/28/22

Description: definitions for methods for LinkedList

Usage: ./createdExecutableName

*/
//node constructor
Node::Node(){
  next = NULL;
  prev = NULL;
}

//node constructor with passed data
Node::Node(int val)
{
  this->data = val;
  this->next = NULL;
  this->prev = NULL;
}

//node constructor with passed data, next and previous nodes
Node::Node(int val, Node* next, Node* prev)
{
  this->data = val;
  this->next = next;
  this->prev = prev;
}

//getters and setters
int Node::getData() { return this->data; }

void Node::setData(int data) { this->data = data; }

Node* Node::getNext() { return this->next; }

void Node::setNext(Node* next) { this->next = next; }

Node* Node::getPrev() { return this->prev; }

void Node::setPrev(Node* prev) { this->prev = prev; }

//linklist constructor
LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

//returns size
int LinkedList::getSize() { return this->size; }

//adds a node to the front with the provided data
void LinkedList::addToFront(int data)
{
  Node* newNode = new Node(data);
  if(head == NULL){
    head = newNode;
    tail = newNode;
  }
  else{
    newNode->setNext(head);
    head->setPrev(newNode);
    head = newNode;
  }
  size++;
}

//adds a node to the end with the provided data
void LinkedList::addToEnd(int data){
  Node* newNode = new Node(data);
  if(head == NULL){
    head = newNode;
    tail = newNode;
  }
  else{
    tail->setNext(newNode);
    newNode->setPrev(tail);
    tail=newNode;
  }
  size++;
}

//adds a node with provided data at a certain index
bool LinkedList::addAtIndex(int data, int index){
  Node* newNode = new Node(data);
  if((index<0) || (index >= size)){
    return false;
  }
  if(index == 0){
    this->addToFront(data);
    return true;
  }
  else{
    if(index == size - 1){
      this->addToEnd(data);
      return true;
    }
  }
  Node* preNode = head;
  for(int i=0; i<index-1; i++){
    preNode = preNode->getNext();
  }
  Node* nexNode = preNode->getNext();
  newNode->setNext(nexNode);
  newNode->setPrev(preNode);
  preNode->setNext(newNode);
  nexNode->setPrev(newNode);
  size++;
  return true;
}

//removes the head
int LinkedList::removeFromFront(){
  Node* temp = head;
  Node* nexTemp = head->getNext();
  int out = temp->getData();
  temp->setNext(NULL);
  nexTemp->setPrev(NULL);
  head = nexTemp;
  size--;
  return out;
}

//removes the tail
int LinkedList::removeFromEnd(){
  Node* temp = tail;
  Node* preTemp = tail->getPrev();
  int out = temp->getData();
  temp->setPrev(NULL);
  preTemp->setNext(NULL);
  tail = preTemp;
  size--;
  return out;
}

//removes the first instance of a node with the provided value
void LinkedList::removeTheFirst(int val){
  if(head->getData() == val){
    this->removeFromFront();
    size--;
    return;
  }
  
  if(tail->getData() == val){
    this->removeFromEnd();
    size--;
    return;
  }
  
  Node* curr = head->getNext();
  while(curr->getNext() != NULL){
    if(curr->getData() == val){
      Node* preCurr = curr->getPrev();
      Node* nexCurr = curr->getNext();
      preCurr->setNext(nexCurr);
      nexCurr->setPrev(preCurr);
      size--;
      return;
    }
    curr = curr->getNext();
  }
  return;  
}

//removes all instances of a node with the provided value
void LinkedList::removeAll(int val){
  for(int i = 0; i<size; i++){
    removeTheFirst(val);
  }
}

//returns 1 if there is a node of the value provided, 0 if not
bool LinkedList::elementExists(int val){
  Node* curr = head;
  if(head->getData() == val){
    return true;
  }
  
  if(tail->getData() == val){
    return true;
  }

  while(curr->getNext() != NULL){
    if(curr->getData() == val){
      return true;
    }
    curr = curr->getNext();
  }
  return false;
}

//returns a node pointer to the node containing the given data
Node* LinkedList::find(int data){
  Node* curr = head;
  if(head->getData() == data){
    return curr;
  }

  if(tail->getData() == data){
    curr = tail;
    return curr;
  }

  while(curr->getNext() != NULL){
    if(curr->getData() == data){
      return curr;
    }
    curr = curr->getNext();
  }
  curr = NULL;
  return curr;
}

//returns the index of a node with the provided data
int LinkedList::indexOf(int data){
  Node* curr = head->getNext();
  if(head->getData() == data){
    return 0;
  }
  
  int i = 1;
  while(curr->getNext() != NULL){
    if(curr->getData() == data){
      return i;
    }
    curr = curr->getNext();
    i++;
  }
  
  if(tail->getData() ==data){
    return size-1;
  }
  return -1;
}

//returns the heads data
int LinkedList::retrieveFront(){
  return head->getData();
}

//returns the tails data
int LinkedList::retrieveEnd(){
  return tail->getData();
}

//prints out the list
void LinkedList::printList(){
  Node* curr = head;
  while(curr != NULL){
    if(curr == tail){
      std::cout<<"("<<curr->getData()<<")"<<std::endl;
      return;
    }
    std::cout<<"("<<curr->getData()<<") -> ";
    curr = curr->getNext();
    
  }
}

//overloading cout
std::ostream& operator<<(std::ostream& out, const LinkedList& self)
{
  Node* current = self.head;
  while(current != NULL)
    {
      out << "[" << current->getData() << "] ->";
      current = current->getNext();
    }
  out << "@";
  return out;
}
