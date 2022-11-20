#include "rai_linklist.h"
#include <iostream>
using namespace std;
/*

Author: Aryan Rai

Date: 4/28/21

Description: Linked List program

Usage: ./createdExecutablename

*/

int main(int argc, char** argv)
{
  //creating the linked list object
  LinkedList list;
  
  //adding 20 nodes
  for(int i = 0; i< 20; i++){
    list.addToFront(i);
  }
  cout<<"Generating linked list of 20 nodes:"<<endl;

  //displaying all the functions of the linked list
  cout << list <<endl;
  for(int i = 0; i< 10; i++){
    list.addToEnd(i);
  }
  cout<<"Adding 10 elements to end using addToEnd:"<<endl;
  cout << list <<endl;
  cout<<"Adding element at index 12 using addAtIndex"<<endl;
  list.addAtIndex(69, 12);
  cout << list << endl;
  cout<<"removing head using removeFromFront"<<endl;
  list.removeFromFront();
  cout << list << endl;
  cout<<"removing tail using removeFromEnd:"<<endl;
  list.removeFromEnd();
  cout << list << endl;
  cout<<"removing first instance of value 69 using removeTheFirst:"<<endl;
  list.removeTheFirst(69);
  cout << list << endl;
  cout<<"removing all instances of 0 using removeAll:"<<endl;
  list.removeAll(0);
  cout << list << endl;
  cout<<"is 0 in the list?"<<endl;
  cout<<list.elementExists(0)<<endl;
  cout<<"is 10 in the list?"<<endl;
  cout<<list.elementExists(10)<<endl;
  cout<<"address of node containing 10 using find function:"<<endl;
  Node* holder = list.find(10);
  cout<< &holder<< endl;
  cout<<"index of node containing 10 using indexOf function:"<<endl;
  cout<<list.indexOf(10)<<endl;
  cout<<"data of head using retrieveFront function:"<<endl;
  cout<<list.retrieveFront()<<endl;
  cout<<"data of tail using retrieveEnd function:"<<endl;
  cout<<list.retrieveEnd()<<endl;
  cout<<"legnth of linked list"<<endl;
  cout << list.getSize() << endl;
  cout<<"printing linked list using printList:"<<endl;
  list.printList();
  return 0;
}
