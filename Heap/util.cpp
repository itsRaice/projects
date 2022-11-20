#include "util.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int checkEx(int argc, char** argv){
  if(argc != 3){
    cerr<<"Usage: ./PJ2 DataStructure Capacity"<<endl;
    cerr<<"       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}"<<endl;
    cerr<<"       Capacity must be a positive integer"<<endl;
    return 0;
  }
  if(string(argv[1]) != "MaxHeap" && string(argv[1]) != "MinHeap" && string(argv[1]) !="DoubleHeap"){
    cerr<<"Usage: ./PJ2 DataStructure Capacity"<<endl;
    cerr<<"       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}"<<endl;
    cerr<<"       Capacity must be a positive integer"<<endl;
    return 0;
  }
  if(atoi(argv[2]) < 0){
    cerr<<"Usage: ./PJ2 DataStructure Capacity"<<endl;
    cerr<<"       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}"<<endl;
    cerr<<"       Capacity must be a positive integer"<<endl;
    return 0;
  }
  else return 1;

}
