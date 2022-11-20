#include "IS.h"
#include <iostream>
using namespace std;
void IS(int* A, int n, int over, int ewc, int& rcount){
  for(int i = 2; i<=n;i++){
    int key = A[i];
    int j = i - 1;
    
    if (A[j]<=key){
      rcount++;
      if(ewc){
         cout<<"EWC: "<<A[j]<<" > "<<key<<"?"<<endl;
      }
    }
    while(j>0 && A[j]>key){
      rcount++;
      //cout<<"ewc is "<<ewc<<endl;
      if(ewc){
	cout<<"EWC: "<<A[j]<<" > "<<key<<"?"<<endl;
      }
      A[j+1] = A[j];

      if(over == 1){
	cout<<"A[1:"<<n<<"]:";
	for(int i = 1; i<=n ; i++){
	  cout<<" "<<A[i];
	}
	cout<<endl;                                                                                                       

      }

      j = j-1;
    }
    
    A[j+1] = key;

    if(over == 1){
      cout<<"A[1:"<<n<<"]:";
      for(int i = 1; i<=n ; i++){
	cout<<" "<<A[i];
      }
      cout<<endl;

    }
  }
  return;
}
