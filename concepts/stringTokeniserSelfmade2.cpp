/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 may 2019
AIM    : to tokenise a string by making our own function
          ---------------   C O U R S E  V E R S I O N   ---------------
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cstring>
using namespace std;

/*bool isThere(char str[], char ch){        // to check if char is a delimiter
  int length = strlen(str);
  for(int i=0; i<length; i++){
    if(ch==str[i])  return true;
  }
  return false;
}*/

char *myStringTokenise(char *str, char delimiter){
  static char*input = NULL;

  if(str!=NULL){        // if new string is recieved, reset the state.
    input=str;
  }
  if(input==NULL){      // check if string got ended
    return NULL;
  }

  char *output = new char[strlen(input)+1];
  int i;
  for(i=0; input[i]!='\0'; i++){
    if(input[i]!=delimiter){
      output[i]=input[i];
    }
    else{
      output[i]='\0';
      input+=i+1;
      return output;
    }
  }
  output[i]='\0';     // return the last word by appending null char
  input=NULL;         // set state of string to be ended for next time
                      // so that we'll be able to return NULL.
  return output;
}

int main(){

char str[]="hello!, i am raghav gupta. i am learning data structres, algos.";
char *ptr;

ptr=myStringTokenise(str, ' ');
while(ptr!=NULL){
  cout<<ptr<<endl;
  ptr=myStringTokenise(NULL, ' ');
}

return 0;
}
