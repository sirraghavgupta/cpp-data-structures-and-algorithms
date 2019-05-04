/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 april 2019
AIM    : to tokenise a string by making our own function
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cstring>
using namespace std;

bool isThere(char str[], char ch){        // to check if char is a delimiter
  int length = strlen(str);
  for(int i=0; i<length; i++){
    if(ch==str[i])  return true;
  }
  return false;
}

char *myStringTokenise(char *str, char *delimiter){

  static char *input=NULL;    // to store the state of the string

  if(str!=NULL){    // if new string is recieved, set the state to new string
    input=str;
  }

  // now u have the string state with which u have to work [may be old one, or new]

  /*create an array to store the tokenise
  use dynamic array, because i have to return this array and use there in main.
  if it will be a static array, its contents will be lost on exiting this function.
  take length to be one more because if the token is the complete string, u will
  need to store the null character.*/
  char *output = new char[strlen(input)+1];


  int i=0;      // to refer to the locations of input arr and output arr
  if(input[i]=='\0')  return NULL;    // if string is empty

  // read the input untill a delimiter is encountered, or a null character
  while(!isThere(delimiter,input[i]) && input[i]!='\0'){
    output[i]=input[i];
    i++;
  }

  // if delimiter was encountered, then return token and set it for next token.
  if(input[i]!='\0'){
    output[i]='\0';
    input+=i+1;
    return output;
  }
  // if null was encountered, means string has ended, so return the current word
  // and set the state to be null for next time as there is no other token.
  else{
    output[i]='\0';
    input+=i;
    return output;
  }
}

int main(){

char str[]="hello!, i am raghav gupta. i am learning data structres, algos.";
char *ptr;

ptr=myStringTokenise(str, " ,");
while(ptr!=NULL){
  cout<<ptr<<endl;
  ptr=myStringTokenise(NULL, " ,");
}

return 0;
}
