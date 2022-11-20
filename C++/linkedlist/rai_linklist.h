#include <iostream>
#pragma once
#ifndef LIST_H
#define LIST_H

/*

Author: Aryan Rai

Date: 4/26/22

Description: Forward declarations for Linked List program

Usage: ./createdExecutableName

*/
class Node{
  //setting up private variables
 private:
  int data;
  Node* prev;
  Node* next;

  //declaring public contstructors and methods
 public:
  Node();
  Node(int);
  Node(int, Node*, Node*);
  ~Node();
  
  int getData();
  void setData(int);
  Node* getNext();
  void setNext(Node*);
  Node* getPrev();
  void setPrev(Node*);

};

class LinkedList{
  //setting up private variables
 private:
  Node* head;
  Node* tail;
  int size;
  
  //setting up public contstructors and methods
 public:
  LinkedList();
  void addToFront(int);
  int getSize();
  void addToEnd(int);
  bool addAtIndex(int, int);
  int removeFromFront();
  int removeFromEnd();
  void removeTheFirst(int);
  void removeAll(int);
  bool elementExists(int);
  Node* find(int);
  int indexOf(int);
  int retrieveFront();
  int retrieveEnd();
  void printList();

  //for overloading cout
  friend std::ostream& operator<<(std::ostream& out, const LinkedList& self);

};

#endif
