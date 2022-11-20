
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include "util.h"
#include "heap.h"

using namespace std;

struct ELEMENT{
  int key;
  int maxpos;
  int minpos;
};

void maxheapify(ELEMENT** A, int i, int size);
void buildmaxheap(ELEMENT** A, int size);
void minheapify(ELEMENT** a, int i, int size);
void buildminheap(ELEMENT** a, int size);
int extractmax(ELEMENT** A, int& rsize, int size, int& rdelpos, int& rADT, ELEMENT** a);
void mindelete(ELEMENT** a, int pos, int size, int& rsize, int& rADT);
int extractmin(ELEMENT** a, int& rsize, int& rdelpos, int& rADT, ELEMENT** A);
void maxdelete(ELEMENT** A, int pos, int& rsize);
int maxincreasekey(ELEMENT** A, int newkey, int pos,int& rADT, ELEMENT** a);
int mindecreasekey(ELEMENT** a, int newkey, int pos,int& rADT, ELEMENT** A);

int main(int argc, char** argv){
  
  int valid = checkEx(argc, argv);
  if(!valid){
    return 0;
  }
  int cap = atoi(argv[2]);
  ELEMENT* arr = new ELEMENT[cap+1];
  ELEMENT** A = new ELEMENT*[cap+1];
  ELEMENT** a = new ELEMENT*[cap+1];
  
  for(int i = 1; i <= cap; i++){
    A[i] = &arr[i];
    a[i] = &arr[i];
    arr[i].maxpos = i;
    arr[i].minpos = i;
  }

  int ADT;
  int& rADT = ADT;
  
  if(string(argv[1]) == "MaxHeap"){ ADT = 1;}
  if(string(argv[1]) == "MinHeap"){ ADT = 2;}
  if(string(argv[1]) == "DoubleHeap"){ ADT = 3;}

  int size = -1;
  int& rsize = size;
  int delpos;
  int& rdelpos = delpos;
  int pos;
  int newkey;
  string com;
  cin >> com;
  switch(ADT)
    {
    case 1:
      while(com.compare("Stop") != 0){
      
	if(com.compare("Print") == 0){
	  if(size == -1){
	    cout << "capacity=" << cap <<", size=0"<<endl;
	  }
	  else{
	    cout << "capacity=" << cap << ", size=" << size << endl;
	    cout << "MaxHeap:";
	    for(int i = 1; i < size; i++){
	      cout << " " << A[i]->key <<",";
	    }
	    cout << " " << A[size]->key << endl;
	    
	    /*
	    //testing
	    cout <<"max positions";
	    for(int i = 1; i <= size; i++){
              cout << " " << A[i]->maxpos;
            }
	    cout << endl;

	    cout <<"min positions";
            for(int i = 1; i <= size; i++){
              cout << " " << A[i]->minpos;
            }
            cout << endl;*/
	  }
	  
	}

	else if(com.compare("Read") == 0){
	  ifstream infile;
	  infile.open("HEAPifile.txt");
	  if(infile.fail()){
	    cerr << "Error: Cannot open file HEAPifile.txt" << endl;
	  }else{
	    infile >> size;
	    if(size <= cap){
	      for(int i = 1; i <= size; i++){
		int temp;
		infile >> temp;
		arr[i].key = temp;
	      }
	    }
	    else{
	      cerr << "Error: Cannot allocate memory for heap" << endl;
	    }
	  }
	  infile.close();
	  if(size <= cap){
	    buildmaxheap(A, size);
	  }
	  
	}
	else if(com.compare("Write") == 0){
	  ofstream outfile;
	  outfile.open("HEAPofile.txt");
	  if(outfile.fail()){
	    cerr << "Error: Cannot open file HEAPofile.txt" << endl;
	  }
	  else if(size == -1){
	    outfile << "capacity=" << cap <<", size=0"<<endl;
	  }
	  else{
	    outfile << "capacity=" << cap << ", size=" << size << endl;
	    outfile << "MaxHeap:";
	    for(int i = 1; i < size; i++){
	      outfile << " " << A[i]->key <<",";
	    }
	    outfile << " " << A[size]->key << endl;
	  }
	}
	else if(com.compare("ExtractMax") == 0){
	  if(size == -1 || size == 0){
	    cerr << "Error: ExtractMax in a min heap or a null/empty heap" << endl;
	  }
	  else{
	    int max = extractmax(A,rsize,size,rdelpos,rADT,a);
	    cout << "ExtractMax: " << max << endl;
	  }
      }
      else if(com.compare("ExtractMin") == 0){
	cerr << "Error: ExtractMin in a max heap or a null/empty heap" << endl;
      }
      else if(com.compare("IncreaseKey") == 0){
	cin >> pos;
	cin >> newkey;
	if(cin.fail()){
	  cerr << "Error: Invalid command" << endl;
	}
	else if(rsize < 1){
	  cerr <<  "Error: IncreaseKey in a min heap or a null/empty heap" << endl;
	}
	else if(pos < 1 || pos > size){
	  cerr << "Error: Invalid position or newKey in IncreaseKey" << endl;
	}
	else if(A[pos]->key >= newkey){
	  cerr << "Error: Invalid position or newKey in IncreaseKey" << endl;
	}
	else{
	  maxincreasekey(A,newkey,pos,rADT,a);
	}
      }
      else if(com.compare("DecreaseKey") == 0){
	cerr << "Error: DecreaseKey in a max heap or a null/empty heap" << endl;
	cin >> pos;
	cin >> newkey;
      }
      else if(com.compare("Insert") == 0){
	cin >> newkey;
	if(cin.fail()){
	  cerr << "Error: Invalid command" << endl;
	}
	else if(rsize >= cap || rsize == -1){
	  cerr << "Error: Insertion to a null/full heap" << endl;
	}
	else{
	  rsize++;
	  A[rsize]->key = -100000;
	  A[rsize]->maxpos = rsize;
	  maxincreasekey(A,newkey,rsize,rADT,a);
	  
	}
      }
      else{
	cerr << "Error: Invalid command" << endl;
      }

      cin >> com;
    }
    
    break;
  case 2:
    while(com.compare("Stop") != 0){

      if(com.compare("Print") == 0){
        if(size == -1){
          cout << "capacity=" << cap <<", size=0"<<endl;
        }
        else{
          cout << "capacity=" << cap << ", size=" << size << endl;
          cout << "MinHeap:";
          for(int i = 1; i < size; i++){
            cout << " " << a[i]->key <<",";
          }
          cout << " " << a[size]->key << endl;
	
	  /*
	  //testing                                                                                                               
	  cout <<"max positions";
	  for(int i = 1; i <= size; i++){
	    cout << " " << a[i]->maxpos;
	  }
	  cout << endl;

	  cout <<"min positions";
	  for(int i = 1; i <= size; i++){
	    cout << " " << a[i]->minpos;
	  }
	  cout << endl;*/
        }

      }

      else if(com.compare("Read") == 0){
        ifstream infile;
        infile.open("HEAPifile.txt");
        if(infile.fail()){
          cerr << "Error: Cannot open file HEAPifile.txt" << endl;
        }else{
          infile >> size;
  if(size <= cap){
    for(int i = 1; i <= size; i++){
      int temp;
      infile >> temp;
      arr[i].key = temp;
    }
  }
  else{
    cerr << "Error: Cannot allocate memory for heap" << endl;
  }
        }
        infile.close();
	if(size <= cap){
	  buildminheap(a,size);
	}
      }
      else if(com.compare("Write") == 0){
	ofstream outfile;
        outfile.open("HEAPofile.txt");
        if(outfile.fail()){
          cerr << "Error: Cannot open file HEAPofile.txt" << endl;
        }
	else if(size ==-1){
          outfile << "capacity=" << cap <<", size=0"<<endl;
	}
        else{
          outfile << "capacity=" << cap << ", size=" << size << endl;
          outfile << "MinHeap:";
          for(int i = 1; i < size; i++){
            outfile << " " << a[i]->key <<",";
          }
          outfile << " " << a[size]->key << endl;
        }
      }
      else if(com.compare("ExtractMax") == 0){
	cerr << "Error: ExtractMax in a min heap or a null/empty heap" << endl;
      }
      else if(com.compare("ExtractMin") == 0){
	if(size == -1 || size == 0){
	  cerr << "Error: ExtractMin in a max heap or a null/empty heap" << endl;
	}
	else{
	  int min = extractmin(a,rsize,rdelpos,rADT,A);
	  cout << "ExtractMin: " << min << endl;
	}
      }
      else if(com.compare("IncreaseKey") == 0){
	cerr << "Error: IncreaseKey in a min heap or a null/empty heap" << endl;
	cin >> pos;
	cin >> newkey;
      }
      else if(com.compare("DecreaseKey") == 0){
        cin >> pos;
        cin >> newkey;
        if(cin.fail()){
          cerr << "Error: Invalid command" << endl;
        }
        else if(rsize < 1){
          cerr <<  "Error: DecreaseKey in a max heap or a null/empty heap" << endl;
        }
        else if(pos < 1 || pos > size){
          cerr << "Error: Invalid position or newKey in DecreaseKey" << endl;
        }
        else if(a[pos]->key <= newkey){
          cerr << "Error: Invalid position or newKey in DecreaseKey" << endl;
        }
        else{
          mindecreasekey(a,newkey,pos,rADT,A);
        }
      }
      else if(com.compare("Insert") == 0){
        cin >> newkey;
        if(cin.fail()){
          cerr << "Error: Invalid command" << endl;
	  //here it is
	  cin.clear();
        }
        else if(rsize >= cap || rsize == -1){
          cerr << "Error: Insertion to a null/full heap" << endl;
        }
        else{
          rsize++;
          a[rsize]->key = 100000;
          a[rsize]->minpos = rsize;
          mindecreasekey(a,newkey,rsize,rADT,A);

        }
      }
      
      else{
        cerr << "Error: Invalid command" << endl;
      }

      cin >> com;
    }
    break;
  case 3:
    while(com.compare("Stop") != 0){

      if(com.compare("Print") == 0){
        if(size == -1){
          cout << "capacity=" << cap <<", size=0"<<endl;
        }
        else{
          cout << "capacity=" << cap << ", size=" << size << endl;
          cout << "MaxHeap:";
          for(int i = 1; i < size; i++){
            cout << " " << A[i]->key <<",";
          }
          cout << " " << A[size]->key <<endl;
	  
	  cout << "MinHeap:";
          for(int i = 1; i < size; i++){
            cout << " " << a[i]->key <<",";
          }
          cout << " " << a[size]->key << endl;

	  /*
	  //testing                                                                                                               
	  cout <<"maxheap max positions";
	  for(int i = 1; i <= size; i++){
	    cout << " " << A[i]->maxpos;
	  }
	  cout << endl;

	  cout <<"maxheap min positions";
	  for(int i = 1; i <= size; i++){
	    cout << " " << A[i]->minpos;
	  }
	  cout << endl;

	  //testing                                                                                                                 
          cout <<"minheap max positions";
          for(int i = 1; i <= size; i++){
            cout << " " << a[i]->maxpos;
          }
          cout << endl;

          cout <<"minheap min positions";
          for(int i = 1; i <= size; i++){
            cout << " " << a[i]->minpos;
          }
          cout << endl;*/

        }

      }

      else if(com.compare("Read") == 0){
        ifstream infile;
        infile.open("HEAPifile.txt");
        if(infile.fail()){
          cerr << "Error: Cannot open file HEAPifile.txt" << endl;
        }else{
          infile >> size;
	  if(size <= cap){
	    for(int i = 1; i <= size; i++){
	      int temp;
	      infile >> temp;
	      arr[i].key = temp;
	            
	    }
	  }
	  else{
	    cerr << "Error: Cannot allocate memory for heap" << endl;
	  }
        }
        infile.close();
	if(size <= cap){
	  buildmaxheap(A,size);
	  buildminheap(a,size);
	}
      }
      else if(com.compare("Write") == 0){
	ofstream outfile;
        outfile.open("HEAPofile.txt");
        if(outfile.fail()){
          cerr << "Error: Cannot open file HEAPofile.txt" << endl;
        }
        else if(size ==-1){
          outfile << "capacity=" << cap <<", size=0"<<endl;
        }
        else{
          outfile << "capacity=" << cap << ", size=" << size << endl;
          outfile << "MaxHeap:";
          for(int i = 1; i < size; i++){
            outfile << " " << A[i]->key <<",";
          }
          outfile << " " << A[size]->key << endl;
	  outfile << "MinHeap:";
	  for(int i = 1; i < size; i++){
            outfile << " " << a[i]->key <<",";
          }
          outfile << " " << a[size]->key << endl;
        }
      }
      else if(com.compare("ExtractMax") == 0){
	if(size == -1 || size == 0){
          cerr << "Error: ExtractMax in a min heap or a null/empty heap" << endl;
        }
	else{
	  int max = extractmax(A,rsize,size,rdelpos,rADT,a);
          cout << "ExtractMax: " << max << endl;
	}
      }
      else if(com.compare("ExtractMin") == 0){
	if(size == -1 || size == 0){
	  cerr << "Error: ExtractMin in a max heap or a null/empty heap" << endl;
	}
	else{
	  int min = extractmin(a,rsize,rdelpos,rADT,A);
          cout << "ExtractMin: " << min << endl;
	}
      }
      else if(com.compare("DecreaseKey") == 0){
        cin >> pos;
        cin >> newkey;
        if(cin.fail()){
          cerr << "Error: Invalid command" << endl;
        }
        else if(rsize < 1){
          cerr <<  "Error: DecreaseKey in a max heap or a null/empty heap" << endl;
        }
        else if(pos < 1 || pos > size){
          cerr << "Error: Invalid position or newKey in DecreaseKey" << endl;
        }
        else if(a[pos]->key <= newkey){
          cerr << "Error: Invalid position or newKey in DecreaseKey" << endl;
        }
        else{
         int maxdec = mindecreasekey(a,newkey,pos,rADT,A);
	 maxheapify(A,maxdec,rsize);
        }
      }
      else if(com.compare("IncreaseKey") == 0){
	cin >> pos;
        cin >> newkey;
        if(cin.fail()){
          cerr << "Error: Invalid command" << endl;
        }
        else if(rsize < 1){
          cerr <<  "Error: IncreaseKey in a min heap or a null/empty heap" << endl;
        }
        else if(pos < 1 || pos > size){
          cerr << "Error: Invalid position or newKey in IncreaseKey" << endl;
        }
        else if(a[pos]->key >= newkey){
          cerr << "Error: Invalid position or newKey in IncreaseKey" << endl;
        }
        else{
	  int mindec = maxincreasekey(A,newkey,pos,rADT,a);
	  minheapify(a,mindec,rsize);
        }
      }
      else if(com.compare("Insert") == 0){
        cin >> newkey;
        if(cin.fail()){
          cerr << "Error: Invalid command" << endl;
        }
        else if(rsize >= cap || rsize == -1){
          cerr << "Error: Insertion to a null/full heap" << endl;
        }
        else{
          rsize++;
          A[rsize]->key = -100000;
          A[rsize]->maxpos = rsize;
	  A[rsize]->minpos = rsize;
          maxincreasekey(A,newkey,rsize,rADT,a);
	  a[rsize]->key = 100000;
	  mindecreasekey(a,newkey,rsize,rADT,A);

        }
      }
      else{
        cerr << "Error: Invalid command" << endl;
      }

      cin >> com;
    }
    break;
    }
  
  delete[] arr;
  delete[] A;
  delete[] a;
  return 0;
}

void maxheapify(ELEMENT** A, int i, int size){
  int l = 2*i;
  int r = (2*i) + 1;
  int largest;

  if(l <= size && A[l]->key > A[i]->key){
    largest = l;
  }
  else {
    largest = i;
  }

  if(r <= size && A[r]->key > A[largest]->key){
    largest = r;
  }
  
  if(largest != i){
    
    ELEMENT* temp;
    int tempmaxpos;

    temp = A[i];
    tempmaxpos = A[i]->maxpos;

    A[i]->maxpos = A[largest]->maxpos;
    A[i] = A[largest];
    //A[i]->maxpos = A[largest]->maxpos;

    A[largest]->maxpos = tempmaxpos;
    A[largest] = temp;
    //A[largest]->maxpos = tempmaxpos;

    maxheapify(A, largest, size);
  }

}

void buildmaxheap(ELEMENT** A, int size){
  for(int i = size/2; i >= 1; i--){
    maxheapify(A, i, size);
  }
}

void minheapify(ELEMENT** a, int i, int size){
  int l = 2*i;
  int r = (2*i)+1;
  int smallest;

  if(l <= size && a[l]->key < a[i]->key){
    smallest = l;
  }
  else {
    smallest = i;
  }

  if(r <= size && a[r]->key < a[smallest]->key){
    smallest = r;
  }

  if(smallest != i){

    ELEMENT* temp;
    int tempminpos;

    temp = a[i];
    tempminpos = a[i]->minpos;

    a[i]->minpos = a[smallest]->minpos;
    a[i] = a[smallest];
    //a[i]->minpos = a[smallest]->minpos;

    a[smallest]->minpos = tempminpos;
    a[smallest] = temp;
    //a[smallest]->minpos = tempminpos;

    minheapify(a, smallest, size);
  }
}

void buildminheap(ELEMENT** a, int size){
  for(int i = size/2; i >= 1; i--){
    minheapify(a, i, size);
  }
}

int extractmax(ELEMENT** A, int& rsize, int size,int& rdelpos,int& rADT, ELEMENT** a){
  int max = A[1]->key;
  rdelpos = A[1]->minpos;
  A[rsize]->maxpos = 1;
  A[1] = A[rsize];
  rsize--;
  
  if(rADT == 3){
    mindelete(a,rdelpos,size,rsize,rADT);
    
  }
  maxheapify(A,1,rsize);
  return max;
}

void mindelete(ELEMENT** a, int pos, int size, int& rsize, int& rADT){
  if(pos > 0 && pos <= rsize+1){
    a[rsize+1]->minpos = a[pos]->minpos;
    a[pos] = a[rsize+1];
    //rsize--;
    if(pos > 1 && pos <= rsize+1 && a[pos]->key < a[pos/2]->key){
      while(pos > 1 && a[pos]->key < a[pos/2]->key){
	ELEMENT* temp;
	int tempminpos;

	temp = a[pos/2];
	tempminpos = a[pos/2]->minpos;

	a[pos/2]->minpos = a[pos]->minpos;
	a[pos/2] = a[pos];

	a[pos]->minpos = tempminpos;
	a[pos] = temp;
	
	pos = pos/2;
      }
    }
    else{
      minheapify(a,pos,rsize+1);
    }
  }
}

int extractmin(ELEMENT** a, int& rsize, int& rdelpos, int& rADT, ELEMENT** A){
  int min = a[1]->key;
  rdelpos = a[1]->maxpos;
  a[rsize]->minpos = 1;
  a[1] = a[rsize];
  rsize--;
  
  if(rADT == 3){
    maxdelete(A,rdelpos,rsize);
  }
  minheapify(a,1,rsize);
  return min;
  
}

void maxdelete(ELEMENT** A, int pos, int& rsize){
  if(pos > 0 && pos <= rsize+1){
    A[rsize+1]->maxpos = A[pos]->maxpos;
    A[pos] = A[rsize+1];
    //rsize--;

    if(pos > 1 && pos <= rsize+1 && A[pos]->key > A[pos/2]->key){
      while(pos > 1 && A[pos]->key > A[pos/2]->key){
        ELEMENT* temp;
        int tempmaxpos;

        temp = A[pos/2];
        tempmaxpos = A[pos/2]->maxpos;

        A[pos/2]->maxpos = A[pos]->maxpos;
        A[pos/2] = A[pos];

        A[pos]->maxpos = tempmaxpos;
        A[pos] = temp;

        pos = pos/2;
      }
    }
    else{
      maxheapify(A,pos,rsize+1);
    }
  }
}

int maxincreasekey(ELEMENT** A, int newkey, int pos, int& rADT, ELEMENT** a){
  A[pos]->key = newkey;
  int outpos = A[pos]->minpos;

  while(pos > 1 && A[pos/2]->key < A[pos]->key){
    
    int tempmaxpos = A[pos/2]->maxpos;
    A[pos/2]->maxpos = A[pos]->maxpos;
    A[pos]->maxpos = tempmaxpos;
    
    ELEMENT* temp = A[pos/2];
    A[pos/2] = A[pos];
    A[pos] = temp;
    
    pos = pos/2;
  }
  return outpos;
}

int mindecreasekey(ELEMENT** a, int newkey, int pos,int& rADT, ELEMENT** A){
  a[pos]->key = newkey;
  int outpos = a[pos]->maxpos;

  while(pos > 1 && a[pos/2]->key > a[pos]->key){

    int tempminpos = a[pos/2]->minpos;
    a[pos/2]->minpos = a[pos]->minpos;
    a[pos]->minpos = tempminpos;

    ELEMENT* temp = a[pos/2];
    a[pos/2] = a[pos];
    a[pos] = temp;

    pos = pos/2;
  }
  return outpos;
}
