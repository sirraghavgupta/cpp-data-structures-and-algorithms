/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 april 2019
AIM    : implement linear linear search on array of strings
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

void linearSearch(string arr[], int n, string key){
  // find a string in an array of strings
  for(int i=0; i<n; i++){
    if(arr[i]==key){
      cout<<"key found at index "<<i<<endl;
      return;
    }
  }
  cout<<"key not found"<<endl;
}

int main(){

  string fruits[10];
  int n;      // number of strings
  cin>>n;
  cin.ignore(); // used to ignore the \n after the value of n is entered
                // without it, the first string input is taken to be \n only
                // which is a blank line

// string input
  for(int i=0; i<n; i++){
    getline(cin, fruits[i]);
  }

// string output
  for(int i=0; i<n; i++){
    cout<<i<<". "<<fruits[i]<<endl;
  }

// linear search
  string key;
  cin>>key;
  linearSearch(fruits, n, key);

return 0;
}
