#include <iostream>
#include "MS.h"
using namespace std;

void mergesort(int* A, int p, int r,int over, int ewc, int& rcount){
  if(p >= r){
    return;
  }

  int q = (p+r)/2;
  mergesort(A,p,q,over,ewc,rcount);
  mergesort(A,q+1,r,over,ewc,rcount);
  merge(A,p,q,r,over,ewc,rcount);
}

void merge(int* A, int p, int q, int r,int over, int ewc, int& rcount){
  int nL = q - p + 1;
  int nR = r-q;
  
  int* L = new int[nL];
  int* R = new int[nR];

  for(int i = 0; i<nL; i++){
    L[i] = A[p+i];
  }
  for(int i = 0; i<nR; i++){
    R[i] = A[q+i+1];
  }
  
  int i = 0;
  int j = 0;
  int k = p;

  while(i<nL && j<nR){
    if(ewc){
      cout<<"EWC: "<<L[i]<<" <= "<<R[j]<<"?"<<endl;
    }
    rcount++;
    if(L[i]<=R[j]){
      A[k] = L[i];
      if(over == 1){
	cout<<"A["<<p<<":"<<r<<"]:";
	for(int x=p;x<=r;x++){
	  cout<<" "<<A[x];
	}
	cout<<endl;
      }
      i++;
    }
    else{
      A[k] = R[j];
      if(over == 1){
	cout<<"A["<<p<<":"<<r<<"]:";
	for(int x=p;x<=r;x++){
          cout<<" "<<A[x];
        }
	cout<<endl;
      }
      j++;
    }
    k++;
  }
  
  while(i<nL){
    A[k] = L[i];
    if(over == 1){
      cout<<"A["<<p<<":"<<r<<"]:";
      for(int x=p;x<=r;x++){
	cout<<" "<<A[x];
      }
      cout<<endl;
    }
    i++;
    k++;
  }
  while(j<nR){
    A[k] = R[j];
    if(over == 1){
      cout<<"A["<<p<<":"<<r<<"]:";
      for(int x=p;x<=r;x++){
	cout<<" "<<A[x];
      }
      cout<<endl;
    }
    j++;
    k++;
  }
}
