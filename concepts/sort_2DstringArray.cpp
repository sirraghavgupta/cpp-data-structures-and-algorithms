/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 april 2019
AIM    : to sort string array in diff ways by modifying the comparator function
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(string a, string b){
  // return a<b;       // for lexicographic order - default method

  /* to sort the strings in decreasing order of length. and if two strings are
     of same length, then sort lexicographically */

  if(a.length() == b.length())
      return a<b;
  else
      return a.length()<b.length();
  // return a.length()<b.length();    // for increasing order of length
}

int main(){

  string fruits[20];
  int n;      // number of strings
  cin>>n;
  cin.ignore();

  // string input
  for(int i=0; i<n; i++){
    getline(cin, fruits[i]);
  }


  // sorting
  sort(fruits, fruits+n, comparator);

  // string output
  for(int i=0; i<n; i++){
    cout<<i<<". "<<fruits[i]<<endl;
  }


return 0;
}
