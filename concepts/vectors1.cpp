/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 may 2019
AIM    : to study the concept of vectors in cpp STL library
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(int a, int b){
  return a>b;
}

int main(){

vector<int> test;
test.reserve(10);
  // toggle the statements and play around to understand.
test.push_back(10);     // insert a value at the end
test.push_back(20);
test.push_back(30);
test.push_back(40);
test.push_back(150);
// test.pop_back();     // remove a value from the end
// test.pop_back();

sort(test.begin(), test.end(), comparator);
// test.clear();        // clear the vector to zero size
cout<<test.size()<<endl;    // number of elements in the vector
cout<<test.capacity()<<endl;  // elements it can hold currently
for(int i=0; i<test.size(); i++){
  cout<<test[i]<<endl;
}

// cout<<test.max_size()<<endl;

cout<<test.front()<<endl;   // get the first element
cout<<test.back()<<endl;    // get the last element
cout<<test.at(2)<<endl;     // get the value at index 2
cout<<test.empty()<<endl;   // if the vector is empty or not
return 0;
}
