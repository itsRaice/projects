#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
/*

Author: Aryan Rai

Date: 3/25/22

Description: morse code to english translator

Usage: morse_assn3 infile.txt -mc infile.mc

*/

//forward declerations
const char* englishToMorse(char);

char morseToEnglish(const char*);


int main(int argc, char** argv)
{
  //making sure all arguments are passed
  string fname = argv[1];
  if(argc == 4){
    
    //create and open outputfile
    ofstream outFile;
    outFile.open(string(argv[3]));

    //translating to morse
    if(string(argv[2]) == "-mc"){
      cout<<"Translating "<<string(argv[1])<<" to Morse"<<endl;

      ifstream input(fname);
    char line[255];

    while(input.getline(line,255,'\n')){
      
      char* token;


      token = strtok(line,"");
      while(token != NULL){
	 
	for(int i = 0; i < strlen(token); i++) 
	  { 
	    
	    char temp = token[i];
	    
	    outFile<<englishToMorse(temp)<<'|';
	  } 
	token = strtok(NULL, "");
	outFile<<'\n';

      }
      
      

      }
  
    }
    //translating to english
      if(string(argv[2]) == "-e"){
	
	cout<<"Translating "<<string(argv[1])<<" to English"<<endl;
	ifstream input(fname);
	char line[255];

	while(input.getline(line,255,'\n')){
	  
	  const char* token;


	  token = strtok(line,"|");
	  while(token != NULL){
	    
	    outFile<<morseToEnglish(token)<<"";
	    token = strtok(NULL, "|");
	    

	  }
	  outFile<<'\n';



	}

      }
      outFile.close();  
      cout<<string(argv[3])<<" file completed."<<endl;
  }
  else
    printf("Error -- usage: <exe> <input file> <-mc|-e> <output file> ");
  //error message if wrong use

  return 0;


}

//switch case for morse translation(i know its supposed to not be 53 statments)
const char* englishToMorse(char letter){
  switch(letter) {

  case 'a' : return ".-";
  case 'A': return ".-";
  case 'b': return "-...";
  case 'B': return "-...";
  case 'c': return "-.-.";
  case 'C': return "-.-.";
  case 'd': return "-..";
  case 'D': return "-..";
  case 'e': return ".";
  case 'E': return ".";
  case 'f': return "..-.";
  case 'F': return "..-.";
  case 'g': return "--.";
  case 'G': return "--.";
  case 'h': return "....";
  case 'H': return "....";
  case 'i': return "..";
  case 'I': return "..";
  case 'j': return ".---";
  case 'J': return ".---";
  case 'k': return "-.-";
  case 'K': return "-.-";
  case 'l': return ".-..";
  case 'L': return ".-..";
  case 'm': return "--";
  case 'M': return "--";
  case 'n': return "-.";
  case 'N': return "-.";
  case 'o': return "---";
  case 'O': return "---";
  case 'p': return ".--.";
  case 'P': return ".--.";
  case 'q': return "--.-";
  case 'Q': return "--.-";
  case 'r': return ".-.";
  case 'R': return ".-.";
  case 's': return "...";
  case 'S': return "...";
  case 't': return "-";
  case 'T': return "-";
  case 'u': return "..-";
  case 'U': return "..-";
  case 'v': return "...-";
  case 'V': return "...-";
  case 'w': return ".--";
  case 'W': return ".--";
  case 'x': return "-..-";
  case 'X': return "-..-";
  case 'y': return "-.--";
  case 'Y': return "-.--";
  case 'z': return "--..";
  case 'Z': return "--..";
  case ' ': return "/";
  case '\0':return "\n";
  default: return "eeee";

  }
}
//translating to english
char morseToEnglish(const char* mor){
  if(strcmp(mor,".-") == 0){
    return 'A';
  }
  else if(strcmp(mor,"-...") == 0){
    return 'B';
  }
  else if(strcmp(mor,"-.-.") == 0){
    return 'C';
  }
  else if(strcmp(mor,"-..") == 0){
    return 'D';
  }
  else if(strcmp(mor,".") == 0){
    return 'E';
  }
  else if(strcmp(mor,"..-.") == 0){
    return 'F';
  }
  else if(strcmp(mor,"--.") == 0){
    return 'G';
  }
  else if(strcmp(mor,"....") == 0){
    return 'H';
  }
  else if(strcmp(mor,"..") == 0){
    return 'I';
  }
  else if(strcmp(mor,".---") == 0){
    return 'J';
  }
  else if(strcmp(mor,"-.-") == 0){
    return 'K';
  }
  else if(strcmp(mor,".-..") == 0){
    return 'L';
  }
  else if(strcmp(mor,"--") == 0){
    return 'M';
  }
  else if(strcmp(mor,"-.") == 0){
    return 'N';
  }
  else if(strcmp(mor,"---") == 0){
    return 'O';
  }
  else if(strcmp(mor,".--.") == 0){
    return 'P';
  }
  else if(strcmp(mor,"--.-") == 0){
    return 'Q';
  }
  else if(strcmp(mor,".-.") == 0){
    return 'R';
  }
  else if(strcmp(mor,"...") == 0){
    return 'S';
  }
  else if(strcmp(mor,"-") == 0){
    return 'T';
  }
  else if(strcmp(mor,"..-") == 0){
    return 'U';
  }
  else if(strcmp(mor,"...-") == 0){
    return 'V';
  }
  else if(strcmp(mor,".--") == 0){
    return 'W';
  }
  else if(strcmp(mor,"-..-") == 0){
    return 'X';
  }
  else if(strcmp(mor,"-.--") == 0){
    return 'Y';
  }
  else if(strcmp(mor,"--..") == 0){
    return 'Z';
  }
  else if(strcmp(mor,"/") == 0){
    return ' ';
  }
  else if(strcmp(mor,"/") == 0){
    return ' ';
  }
  else return '#';

}
