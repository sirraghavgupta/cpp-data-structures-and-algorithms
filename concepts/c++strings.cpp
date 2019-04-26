/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 april 2019
AIM    : basics of string library
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(string a, string b){
  // return (a.length()>b.length());   // increasing order of length
  // return (a.length()<b.length());   // decreasing order of length
  // return a<b;                       // default , lexicographclly
  return a>b;                          // reverse lexicographically
}
/* by default, the <operator is overloaded on string class. it checks
if the string 1 comes b4 the string2 in the lexicograph*/


int main(){

// different ways to initialise a string
string s1="raghav";
string s2=s1;
string s3("gunjan gupta");
string s4(s3);

// verify all the strings
cout<<s1<<endl;
cout<<s1.length()<<endl;

cout<<s2<<endl;
cout<<s2.length()<<endl;

cout<<s3<<endl;
cout<<s3.length()<<endl;

cout<<s4<<endl;
cout<<s4.length()<<endl;
// cout<<strlen(s3)<<endl;     // u need cstring header for this.


// ===================================================================
cin>>s1;
cout<<s1<<endl;   // input single word string

fflush(stdin);     // clear buffer before getline always.
getline(cin,s1);   // input a sentence string
cout<<s1<<endl;

// ------------------ string array ------------------------
string fruits[10] = {"apple", "mango", "banana", "pineapple", "guava", "strawberry"};
for(int i=0; i<6; i++){
  cout<<fruits[i]<<endl;
}

cout<<"------- sorted array --------"<<endl;

sort(fruits, fruits+6, comparator);
// comparator function is optional parameter, decides the way of sorting

for(int i=0; i<6; i++){
  cout<<fruits[i]<<endl;
}


return 0;
}
