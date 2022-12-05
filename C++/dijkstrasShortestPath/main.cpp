#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cfloat>

using namespace std;

struct vertex{
  int index;
  char color;
  float key;
  int pre;
  int pos;
};

struct edge{
  int index;
  int u;
  int v;
  float w;
  bool direct;
  edge* next;
};

void minheapify(vertex** heap, int i, int size);
void buildminheap(vertex** heap, int size);
int extractmin(vertex** heap, int& s);
void mindecreasekey(vertex** heap, float newkey, int pos);

int main(int argc, char** argv){

  int valid;
  if(argc != 3){
    cerr << "Usage: ./PJ3 <GraphType> <InputFile>" << endl;
    valid = 0;
  }
  else if(string(argv[1]) != "Directed" && string(argv[1]) != "Undirected"){
    cerr << "Usage: ./PJ3 <GraphType> <InputFile>" << endl;
    valid = 0;
  }
  else {
    valid = 1;
  }
  if(!valid){
    return 0;
  }

  string filename = string(argv[2]);
  string graph = string(argv[1]);

  int v, e;

  ifstream infile;

  infile.open(filename);
  
  if(infile.fail()){
    cerr << "file open error" << endl;
    return 0;
  }

  infile >> v >> e;
  
  if(graph == "Undirected"){
    e = e*2;
  }

  vertex* V = new vertex[v+1];
  vertex** heap = new vertex*[v+1];
  edge* E =  new edge[e+1];
  edge** ADJ = new edge*[v+1];
  //int* stck = new int[v+1];
  //int stckpos = 0;

  if(graph == "Directed"){
    for(int i = 1; i <= e; i++){
      infile >> E[i].index >> E[i].u >> E[i].v >> E[i].w;
    }
  }else{
    for(int i = 1; i <= e; i+=2){
      infile >> E[i].index >> E[i].u >> E[i].v >> E[i].w;
      E[i+1].index = E[i].index;
      E[i+1].u = E[i].v;
      E[i+1].v = E[i].u;
      E[i+1].w = E[i].w;
    }
  }
  infile.close();

  for(int i = 0; i<= v; i++){
    ADJ[i] = NULL;
    V[i].pos = i;
    V[i].index = i;
    heap[i] = &V[i];
  }

  for(int i = 1; i <= e; i++){
    edge* curr = &E[i];
    curr->next = ADJ[E[i].u];
    ADJ[E[i].u] = curr;
  }

  int size = v;
  int savesize = size;
  int& s = size;
  int src = -1;
  int dest = -1;

  string com;
  cin >> com;

  while(com.compare("Stop") != 0){

    if(com.compare("SinglePair") == 0){
      
      cin >> src >> dest;

      if(cin.fail()){
	cerr << "Invalid Command." << endl;
	cin.clear();
      }else{
        //algo
	size = savesize;
        for(int i = 1; i <= v; i++){
          V[i].key = FLT_MAX;
          V[i].pre = -1;
        }
        V[src].key = 0;

        for(int i = 1; i <= v; i++){
          heap[i] = &V[i];
        }
        buildminheap(heap,s);

        while(s > 0){
          int u = extractmin(heap,s);
	  if(dest == u){
	    break;
	  }
          //cout << "u: " << u << endl;
          edge* trav = ADJ[u];
          while(trav != NULL){
            if(V[trav->v].key > (V[u].key + trav->w)){
              mindecreasekey(heap,V[u].key + trav->w,V[trav->v].pos);
              V[trav->v].pre = u;
            }
            trav = trav->next;
          }

        }
      }
    }
    else if(com.compare("SingleSource") == 0){

      cin >> src;

      if(cin.fail()){
	cerr <<"Invalid Command." << endl;
	cin.clear();
      }else{
	//algo
	size = savesize;
	for(int i = 1; i <= v; i++){
	  V[i].key = FLT_MAX;
	  V[i].pre = -1;
	}
	V[src].key = 0;
	
	for(int i = 1; i <= v; i++){
	  heap[i] = &V[i];
	}
	buildminheap(heap,s);

	while(s > 0){
	  int u = extractmin(heap,s);
	  //cout << "u: " << u << endl;
	  edge* trav = ADJ[u];
	  while(trav != NULL){
	    if(V[trav->v].key > (V[u].key + trav->w)){
	      mindecreasekey(heap,V[u].key + trav->w,V[trav->v].pos);
	      V[trav->v].pre = u;
	    }
	    trav = trav->next;
	  }

	}
	
	//tester
	/*
	for(int i = 1; i <= v; i++){
	  cout << i << " " << V[i].index << " " << V[i].key << " "<< V[i].pre << endl;
	  }*/
      }
    }
    else if(com.compare("PrintPath") == 0){
      int nsrc, ndest;
      cin >> nsrc >> ndest;

      if(cin.fail()){
	cerr <<"Invalid Command." << endl;
	cin.clear();
      }else{
	//algo
	if(src == -1 || src != nsrc){
	  //cout<< "There is no path from " << nsrc << " to " << ndest << "." << endl;
	}
	else if(dest != -1 && ndest != dest){
	  //cout<< "There is no path from " << nsrc << " to " << ndest <<"." << endl;
	}
	else{
	  int* path = new int[v+1];
	  int pathc = 1;
	  int pretrack = V[ndest].pre;
	  path[pathc] = ndest;
	  while(pretrack != -1){
	    pathc++;
	    path[pathc]=pretrack;
	    pretrack = V[pretrack].pre;
	  }
	  if(path[pathc] != nsrc){
	    cout<< "There is no path from " << nsrc << " to " << ndest <<"." << endl;
	  }
	  else{
	    cout<< "The shortest path from " << nsrc << " to " << ndest <<" is:" << endl;
	    for(int i = pathc; i > 1; i--){
	      printf("[%d:%8.2f]-->", path[i], V[path[i]].key);
	    }
	    printf("[%d:%8.2f].\n", path[1], V[path[1]].key);
	  }
	  delete[] path;
	}
      }
    }
    else if(com.compare("PrintLength") == 0){
      int nsrc,ndest;
      cin >> nsrc >> ndest;

      if(cin.fail()){
        cerr <<"Invalid Command." << endl;
	cin.clear();
      }else{
	
	//algo
	if(src == -1 || src != nsrc){
          //cout<< "There is no path from " << nsrc << " to " << ndest << "." << endl;
        }
        else if(dest != -1 && ndest != dest){
          //cout<< "There is no path from " << nsrc << " to " << ndest <<"." << endl;
        }
        else{
	  if(V[ndest].key == FLT_MAX){
	    cout<< "There is no path from " << nsrc << " to " << ndest <<"." << endl;
	  }
	  else{
	    printf("The length of the shortest path from %d to %d is: %8.2f\n",nsrc,ndest,V[ndest].key);
	  }
	}
      
      }
    }
  else if(com.compare("PrintADJ") == 0){
    
    for(int i = 1; i <= v; i++){                                                                                                      
      cout << "ADJ[" << i << "]:";                                                                                                    
      edge* curr = ADJ[i];                                                                                                            
      while(curr != NULL){                                                                                                            
	printf("-->[%d %d: %4.2f]",curr->u, curr->v, curr->w);                                                                         
	curr = curr->next;                                                                                                            
      }                                                                                                                               
      cout << endl;                                                                                                                   
    }

  }
    else{
      cerr << "Invalid command."<< endl;
    }
    

    cin >> com;
  }
  
  delete[] V;
  delete[] heap;
  delete[] E;
  delete[] ADJ;
  return 0;
}

void minheapify(vertex** heap, int i, int size){
  int l = 2*i;
  int r = (2*i)+1;
  int smallest;

  if(l <= size && heap[l]->key < heap[i]->key){
    smallest = l;
  }
  else {
    smallest = i;
  }

  if(r <= size && heap[r]->key < heap[smallest]->key){
    smallest = r;
  }
  
  if(smallest != i){

    vertex* temp;
    int temppos;

    temp = heap[i];
    temppos = heap[i]->pos;

    heap[i]->pos = heap[smallest]->pos;
    heap[i] = heap[smallest];
    //a[i]->minpos = a[smallest]->minpos;

    heap[smallest]->pos = temppos;
    heap[smallest] = temp;
    //a[smallest]->minpos = tempminpos;

    minheapify(heap, smallest, size);
  }

}

void buildminheap(vertex** heap, int size){
  for(int i = size/2; i >= 1; i--){
    minheapify(heap, i, size);
  }
}

int extractmin(vertex** heap, int& s){
  int min = heap[1]->index;
  heap[s]->pos = 1;
  heap[1]= heap[s];
  s--;
  
  minheapify(heap,1,s);
  return min;
}

void mindecreasekey(vertex** heap, float newkey, int pos){
  heap[pos]->key = newkey;
  
  while(pos > 1 && heap[pos/2]->key > heap[pos]->key){
    int temppos = heap[pos/2]->pos;
    heap[pos/2]->pos = heap[pos]->pos;
    heap[pos]->pos = temppos;

    vertex* temp = heap[pos/2];
    heap[pos/2] = heap[pos];
    heap[pos] = temp;
    
    pos = pos/2;
  }
}
