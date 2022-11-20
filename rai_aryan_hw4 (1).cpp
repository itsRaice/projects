/* 
Name: Aryan Rai  
Date: 4/8/2022 
Description: Creating island map using particle roll algorithim 
Usage: ./executablename (optional: -s seedInt) 
*/

#include <iostream>
#include <time.h>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

//function forward declarations
double frand();
bool canmove(int**,int,int,int,int);


int main(int argc, char** argv){
  //creating necessary variables
  int rows;
  int cols;
  int** table;
  char** ctable;
  int Cx;
  int Cy;
  int rad;
  int parts;
  int life;
  int water;
  int max = 1;

  //using seed for RNG if provided
  if(argc == 3){
  
    long seed = strtol(argv[2], NULL, 10);
    if((strcmp(argv[1],"-s")) == 0){
      srand(seed);
    }
    else{
      srand(time(0));
    }
  }

  //creating output file
  ofstream outfile;
  outfile.open("island.txt");

  //user prompts
  cout<<"Welcome to Aryan Rai's CSE240 island generator!"<<endl;
  cout<<endl;
  cout<<"Enter rows: ";
  cin >> rows;
  cout<<"Enter cols: ";
  cin >> cols;
  //making sure entries are within bounds
  cout<<"Enter drop-zone x-coordinate (0 - "<< cols<<"): ";
  cin>>Cx;
  if(Cx<=0 || Cx>=cols){
    cout<<"Out of range, reenter within (0 - "<< cols<<"): ";
    cin>>Cx;
  }
  
  cout<<"Enter drop-zone y-coordinate (0 - "<< rows<<"): ";
  cin>>Cy;
  if(Cy<=0 || Cy>=rows){
    cout<<"Out of range, reenter within (0 - "<< rows<<"): ";
    cin>>Cy;
  }
  cout<<"Enter drop-zone radius(minimum 2): ";
  cin>>rad;
  if((Cx+rad)>=cols || (Cx-rad)<=0 || (Cy+rad)>=rows || (Cy+rad)<=0){
    cout<<"Out of range, reenter radius): ";
    cin>>rad;
  }
  
  cout<<"Enter number of particles to drop: ";
  cin>>parts;
  cout<<"Enter max life of particles: ";
  cin>>life;
  cout<<"Enter value for waterline(40-200): ";
  cin>>water;
  cout<<endl;

  //dynamically allocating 2D array
  table = new int*[rows];
  for(int row = 0; row < rows; row++){
    table[row] = new int[cols];
  }

  for(int y = 0; y < rows; y++){
    for(int x = 0; x < cols; x++){
      table[y][x] = 0;
    }
  }
 
  //particle roller
  for(int i = 0;i<parts;i++){

    double therand = frand();

    double r = rad * sqrt(therand);
    double theta = therand * 2 * M_PI;
  
    int x = (int)(Cx + r * cos(theta));
    int y = (int)(Cy + r * sin(frand() * 2 * M_PI));


    table[y][x] = table[y][x]+1;
    //picks random possible moves until out of lives left
    for(int i = 0; i<life;i++){
      if(canmove(table,x,y,rows,cols)){

	int moved = -1;
	while(moved == -1){
	  int cmove = (rand() % 8) + 1;
	  int nx;
	  int ny;
	  switch(cmove){
	  case 6:
	    nx = x+1;
	    ny = y+1;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx]= table[ny][nx]+1;
	      x =  nx;
	      y = ny;
	      moved = 2;
	    }
	    break;
	  case 1:
	    nx = x-1;
	    ny = y;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx] = table[ny][nx]+1;
	      x = nx;
	      y = ny;
	      moved = 2;
	    }
	    break;
	  case 2:
            nx = x-1;
            ny = y-1;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx] = table[ny][nx]+1;
	      x = nx;
	      y = ny;
	      moved = 2;
	    }
            break;
	  case 3:
            nx = x;
            ny = y-1;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx] = table[ny][nx]+1;
	      x = nx;
	      y = ny;
	      moved = 2;
	    }
            break;
	  case 4:
            nx = x+1;
            ny = y-1;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx] = table[ny][nx]+1;
	      x = nx;
	      y = ny;
	      moved = 2;
	    }
            break;
	  case 5:
            nx = x+1;
            ny = y;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx] = table[ny][nx]+1;
	      x = nx;
	      y = ny;
	      moved = 2;
	    }
            break;
	  case 7:
            nx = x;
            ny = y+1;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx] = table[ny][nx]+1;
	      x = nx;
	      y = ny;
	      moved = 2;
	    }
            break;
	  case 8:
            nx = x-1;
            ny = y+1;
	    if(table[ny][nx]<=table[y][x]){
	      table[ny][nx] = table[ny][nx]+1;
	      x = nx;
	      y = ny;
	      moved = 2; 
	    }
            break;
	  }

	}

      }
    }
  }
  //finding max
  for(int y = 0; y < rows; y++){
    for(int x =0; x < cols; x++){
      if(table[y][x]>max){
        max = table[y][x];
      }
    }
  }
  //begin outputting to console and file
  cout<<"Raw Island:"<<endl;
  outfile<<"Raw Island:"<<endl;

  for(int y = 0; y < rows; y++){
    for(int x =0; x < cols; x++){
      cout<<setw(3);
      cout<<table[y][x]<<" ";
      outfile<<setw(3);
      outfile<<table[y][x]<<" ";
    }
    cout<<endl;
    outfile<<endl;
  }
  
  cout<<endl;
  outfile<<endl;

  //normalizing island values 
  float temp;
  for(int y = 0; y < rows; y++){
    for(int x =0; x < cols; x++){
      temp = (float)table[y][x]/(float)max;
      table[y][x] = (int)(temp*255);
      
    }
  }
  
  //creating 2D character array for polished island
  ctable = new char*[rows];
  for(int row = 0; row < rows; row++){
    ctable[row] = new char[cols];
  }

  //swapping numbers with appropriate characters
  int land = 255 - water;
  for(int y = 0; y < rows; y++){
    for(int x = 0; x < cols; x++){
      ctable[y][x] = '0';
      if(table[y][x]<=water){

	ctable[y][x]= '#';
	
	if(table[y][x]> (water/2)){
	  ctable[y][x] = '~';
	}
	
      }
      else{ 
	ctable[y][x] = '.';
      }
      if(table[y][x]>=(water+(0.15*land))){
	ctable[y][x] = '-';
      }
      if(table[y][x]>=(water+(0.4*land))){
        ctable[y][x] = '*';
      }
      if(table[y][x]>=(water+(0.8*land))){
        ctable[y][x] = '^';
      }
    }
  }

  //outputting normalized island
  cout<<"Normalized Island:"<<endl;
  outfile<<"Normalized Island:"<<endl;
  
  for(int y = 0; y < rows; y++){
    for(int x =0; x < cols; x++){
      cout<<setw(3);
      cout<<table[y][x]<<" ";
      outfile<<setw(3);
      outfile<<table[y][x]<<" "; 
    }
    cout<<endl;
    outfile<<endl;
  }

  cout<<endl;
  outfile<<endl;

  //outputting polished island
  cout<<"Polished Island:"<<endl;
  cout<<setw(1);
  outfile<<"Polished Island:"<<endl;
  outfile<<setw(1);
  for(int y = 0; y < rows; y++){
    for(int x =0; x < cols; x++){
      cout<<ctable[y][x];
      cout<<setw(1);
      outfile<<ctable[y][x];
      outfile<<setw(1);
    }
    cout<<endl;
    outfile<<endl;
  }

  //closing file and freeing memory
  outfile.close();


  for(int x =0; x < cols; x++){
    delete[] table[x];
    delete[] ctable[x];
  }
  delete[] table;
  delete[] ctable;
  
  return 0;
}

//generates random number between 0 and 1
double frand(){
  return (double)rand() / (double)RAND_MAX;
}

//determines if any moves are available
bool canmove(int** table, int x, int y, int rows, int cols){
  if((1 <= x)&& (x <= (cols-2)) && (1<= y) && (y <= (rows-2))){
    if((table[y][x-1]<table[y][x]) || (table[y-1][x-1]<table[y][x]) || (table[y-1][x]<table[y][x]) ||
       (table[y-1][x+1]<table[y][x]) || (table[y][x+1]<table[y][x]) || (table[y+1][x+1]<table[y][x]) ||
       (table[y+1][x]<table[y][x]) || (table[y+1][x-1]<table[y][x])){
      return true;


    }
    else return false;
  }
  else return false;
}

// :)
