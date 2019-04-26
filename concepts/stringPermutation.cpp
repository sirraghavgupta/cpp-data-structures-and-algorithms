/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 april 2019
AIM    : to check if two strings are permutations of each other or not
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cstring>
using namespace std;

// to count the number of occurences of all charcters in a string
void countChars(char string[], int frequency[]){
  for(int i=0; i<strlen(string); i++){
    int index= string[i]-'a';
    frequency[index]++;
  }
}

int main(){

char string1[20], string2[20];
int frequency1[26]={0}, frequency2[26]={0};    // for counting

cin>>string1;
// cout<<"u entered: "<<string1<<endl;
cin>>string2;
// cout<<"u entered: "<<string2<<endl;

countChars(string1, frequency1);
countChars(string2, frequency2);


// match the 2 frequency arrays
for(int i=0; i<26; i++){
  if(frequency1[i] != frequency2[i]){
    cout<<"not a permutation"<<endl;
    return 0;
  }
}
cout<<"yes!! permutation detected."<<endl;

return 0;
}
