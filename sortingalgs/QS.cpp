#include "QS.h"
#include <iostream>
using namespace std;

void quicksort(int* A, int p, int r,int over, int ewc, int& rcount){
  if(p<r){
    int q = partition(A,p,r,over,ewc,rcount);
    quicksort(A,p,q-1,over,ewc,rcount);
    quicksort(A,q+1,r,over,ewc,rcount);
  }
}

int partition(int* A, int p, int r,int over,int ewc,int& rcount){
  int x = A[r];
  int i = p-1;
  for(int j = p; j<=r-1; j++){
    rcount++;
    if(ewc){
      cout<<"EWC: "<<A[j]<<" <= "<<x<<"?"<<endl;
      //rcount++;
    }
    if(A[j]<=x){
      i++;
      int temp = A[i];
      A[i] = A[j];
      if(over == 1){
        cout<<"A["<< p <<":" <<r <<"]:";
        for(int i = p; i<=r ; i++){
          cout<<" "<<A[i];
        }
        cout<<endl;

      }
      A[j] =  temp;
      if(over == 1){
	cout<<"A["<< p <<":" <<r <<"]:";
	for(int i = p; i<=r ; i++){
	  cout<<" "<<A[i];
	}
	cout<<endl;                                                                                                       

      }
    }
  }
  int temp = A[i+1];
  A[i+1] = A[r];
  if(over == 1){
    cout<<"A["<< p <<":" <<r <<"]:";
    for(int i = p; i<=r ; i++){
      cout<<" "<<A[i];
    }
    cout<<endl;

  }
  A[r] = temp;
  if(over == 1){
    cout<<"A["<<p<<":"<<r<<"]:";
    for(int i = p; i<=r ; i++){
      cout<<" "<<A[i];
    }
    cout<<endl;

  }
  return i+1;
}
