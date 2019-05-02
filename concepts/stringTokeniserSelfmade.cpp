/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 april 2019
AIM    : to tokenise a string by making our own function
STATUS :
##############################################################################*/
#include <iostream>
#include <cstring>
using namespace std;

char *myStringTokenise(char *str, char delimiter){

  // cout<<"inside the function"<<endl;
  static char *input=NULL;

  if(str!=NULL){
    input=str;
  }

  char *output = new char[strlen(input)+1];
  int i=0;
  if(input[i]=='\0')  return NULL;
  while(input[i]!=delimiter && input[i]!='\0'){
    output[i]=input[i];
    i++;
  }

  if(input[i]!='\0'){
    output[i]='\0';
    input+=i+1;
    return output;
  }

  /*  for(int i=0; input[i]!='\0'; i++){
      if(input[i]!=delimiter){
        output[i]=input[i];
      }
      else{
        input+=i+1;
      }
    }
    output[i]='\0';
    return output;
  }
  else{

  }*/
}

int main(){

char str[] = "hello!, i m raghav.i am learning c++, data structures and prog.";
char *ptr;

ptr=myStringTokenise(str, ' ');

while(ptr!=NULL){
  cout<<ptr<<endl;
  ptr=myStringTokenise(NULL, ' ');
}

return 0;
}
