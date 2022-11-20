#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "IS.h"
#include "QS.h"
#include "MS.h"
using namespace std;

int main(int argc, char** argv){

  if(argc != 3){
    cout<<"Usage: ./PJ1 alg flag"<<endl;
    cout<<"       alg should be in {InsertionSort, MergeSort, QuickSort}"<<endl;
    cout<<"       flag should be in {0, 1}"<<endl;
    return 0;
  }

  if(string(argv[1]) != "InsertionSort" && string(argv[1]) != "MergeSort" && string(argv[1]) !="QuickSort"){
    cout<<"Usage: ./PJ1 alg flag"<<endl;
    cout<<"       alg should be in {InsertionSort, MergeSort, QuickSort}"<<endl;
    cout<<"       flag should be in {0, 1}"<<endl;
    return 0;
  }

  if(string(argv[2]) != "1" && string(argv[2]) !=  "0"){
    cout<<"Usage: ./PJ1 alg flag"<<endl;
    cout<<"       alg should be in {InsertionSort, MergeSort, QuickSort}"<<endl;
    cout<<"       flag should be in {0, 1}"<<endl;
    return 0;
  }
  
  int printEWC = atoi(argv[2]);
  //cout<<printEWC<<endl;
  int printA, printR, num;
  ifstream infile;
  infile.open("INPUT.txt");
  if(infile.fail()){
    cout<<"Error: cannot open file INPUT.txt"<<endl;
    //cout<<"Number of EWC's: 0"<<endl;
    return 0;
  }
  infile >> printR >> printA >> num;
  //cout<< printR <<" "<< printA <<" "<< num <<endl;
  int* A = new int[num+1];
  for(int i = 1;i<=num;i++){
    infile>>A[i];
  }
  infile.close();

  
  int alg;

  if(string(argv[1]) == "InsertionSort"){
    alg = 1;
  }
  if(string(argv[1]) == "MergeSort"){
    alg = 2;
  }
  if(string(argv[1]) =="QuickSort"){
    alg = 3;
  }

  int count= 0;
  int& rcount = count;
  
  
  switch(alg){
  case 1:
    IS(A,num,printA,printEWC,rcount);
    break;
  case 2:
    mergesort(A,1,num,printA,printEWC,rcount);
    break;
  case 3:
    quicksort(A,1,num,printA,printEWC,rcount);
    break;

  }
 

  if(printR){
    cout<<"A[1:"<<num<<"] after sorting:";
    for(int i = 1; i<=num ; i++){
      cout<<" "<<A[i];
    }
    cout<<endl;
  }

  cout<<"Number of EWCs: "<<count<<endl;
  delete [] A;

  return 0;
}

