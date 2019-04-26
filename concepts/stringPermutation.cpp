/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 april 2019
AIM    : to check if two strings are permutations of each other or not
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cstring>
using namespace std;

/* //to count the number of occurences of all charcters in a string
void countChars(char string[], int frequency[]){
  for(int i=0; i<strlen(string); i++){
    int index= string[i]-'a';
    frequency[index]++;
  }
} */

int main(){

char string1[20], string2[20];
int frequency1[26]={0};    // for counting

cin>>string1;
cin>>string2;

if(strlen(string1)!=strlen(string2)){   // length should be same for permutation
  cout<<"not a permutation"<<endl;
  return 0;
}

// prepare freq array for string 1
for(int i=0; i<strlen(string1); i++){
  int index= string1[i]-'a';
  frequency1[index]++;
}

// for second string, go on decrementing the first freq array
for(int i=0; i<strlen(string2); i++){
  int index= string2[i]-'a';
  frequency1[index]--;
}

// check if the freq array has become all 0
for(int i=0; i<26; i++){
  if(frequency1[i]!=0){
    cout<<"not a permutation"<<endl;
    return 0;
  }
}
cout<<"yes!! permutation detected."<<endl;

return 0;
}
