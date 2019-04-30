/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 april 2019
AIM    : to sort a 2D char array [strings] in lexicographic manner
          ----------  B U B B L E   S O R T ----------
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cstring>
using namespace std;

/* NOTE ABOUT STRCMP FUNCTION :-
   strcmp - returns 0 value if the two strings are perfectly same.
          - returns positive value if the first string comes b4 the second in
          lexicographic order
          - returns negative value if the first string comes after the second in 
          lexicographic order*/

void stringSort(char arr[][100], int n){
  // ----------- using bubble sort ---------
cout<<"inside the function"<<endl;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      char temp[100];
      if(strcmp(arr[i],arr[j])>0){
        strcpy(temp,arr[j]);
        strcpy(arr[j],arr[i]);
        strcpy(arr[i],temp);
      }
    }
  }
}

int main(){

char fruits[20][100];
int n;
cin>>n;
// cin.ignore();      // choice is there b\w get and ignore... .do same work here
cin.get();

// read n strings
for(int i=0; i<n; i++){
  cin.getline(fruits[i],100);
}

stringSort(fruits, n);

// display n strings
for(int i=0; i<n; i++){
  cout<<fruits[i]<<endl;
}

return 0;
}
