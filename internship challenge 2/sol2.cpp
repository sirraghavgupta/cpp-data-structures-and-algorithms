// ##############################################################################
// AUTHOR : RAGHAV GUPTA
// DATE   : 26 august 2019
// AIM    : to solve this problem by using different vectors for keys and values
// STATUS : 
// ##############################################################################

// ------------------------------- headers included -------------------------
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

int main(){

// ----------------------------------- clocking part ------------------------
clock_t start, end;
start=clock();


// ------------- main objects ------------------------------
fstream fin;      // input file stream
string word;      // for extracting word [key/ value] from a line
vector<string> keys;     //to store all the keys/ values
vector<string> values;


// --------------- reading file input - creating dataset -------------------
fin.open("input.csv",ios::in);

while(!fin.eof()){
  getline(fin, word, ',');
  keys.push_back(word);
  getline(fin, word);
  values.push_back(word);
}

/*    cout<<keys.size()<<endl;   // size of input
cout<<values.size()<<endl;

// ------------------------------ print the dataset -------------------------
for(int i=0; i<100;i++){
  cout<<keys[i]<<","<<values[i]<<endl;
}  */


fin.close();
// -------------------- end input task -------------------------------


/*
----------------------- S O R T I N G - L O G I C --------------------------
sort(keys.begin(), keys.end(), compare);
sort(values.begin(), values.end(), compared);
cout<<keys.size();
for(int i=0; i<100;i++){
  cout<<keys[i]<<endl;
}
return 0;
------------- sorting logic failed because the values vector could not be sorted
corresponding to the keys vector, need of different data structure found ----
*/


// -------------------- input test data -------------------------------
vector<string> test_keys;   // for holding test keys
vector<string> corr_values; // for holding target values
fin.open("test.txt", ios::in);
while(!fin.eof()){
  getline(fin, word);
  test_keys.push_back(word);
}

/*
// cout<<test_keys.size()<<endl;    // check the size of the test data
// ----------------------- print the test data -----------------------
for(int i=0; i<100; i++){
  cout<<test_keys[i]<<endl;
}
*/


// -------------------------- looking up ---------------------------
vector<string>::iterator it;
for(int i=0; i<test_keys.size(); i++){
    it = find (keys.begin(), keys.end(), test_keys[i]);
    int index=it - keys.begin();
    corr_values.push_back(values[index]);
}

/*   cout<<corr_values.size()<<endl;      // check size of output data

for(int i=0; i<100; i++){            // print the values
  cout<<test_keys[i]<<","<<corr_values[i]<<endl;
}     */


/*
// ----------------- memory space consumed ---------------------
cout<<test_keys.capacity()<<endl;
cout<<corr_values.capacity()<<endl;
cout<<keys.capacity()<<endl;
cout<<values.capacity()<<endl;
*/



// ----------------------------- clocking part ---------------------------
end=clock();
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
cout<<fixed<<time_taken<<setprecision(5)<<endl;
cout<<"sec";

return 0;
}
