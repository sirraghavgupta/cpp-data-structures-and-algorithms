#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int main(){

// ----------------------------------- clocking part ------------------------
clock_t start, end;
start=clock();



// empty map container
    map<string, string> datamap;
    ifstream fin;

// create the dataset in hashmap
    fin.open("input.csv");
    string key, value;
    while(getline(fin,key,',')){
      getline(fin,value);
      datamap.insert(pair<string, string>(key, value));
    }
    fin.close();



// printing map datamap
        /*map<string, string>::iterator mapprinter;
        int count=0;                                  // print only 100 values
        cout << "\tKEY\tELEMENT\n";
        for (mapprinter = datamap.begin(); count<100; ++mapprinter) {
            cout << '\t' << mapprinter->first
                 << '\t' << mapprinter->second << '\n';
            count++;
        }
        cout << endl;*/



// create the test data in string vector
    vector<string> test_keys;
    fin.open("test.txt");
    while(fin>>key){
      test_keys.push_back(key);
    }
    fin.close();



// print the test data
  /*int count=0;
  vector<string>::iterator keyprinter;
    for(keyprinter=test_keys.begin(); keyprinter!=test_keys.end(); ++keyprinter){
      cout<<++count<<". "<<*keyprinter<<endl;
    }*/


// lookup for values
vector<string> corr_values;                 // to hold the output values
map<string, string>::iterator searcher;
for(int i=0; i<test_keys.size(); i++){
    searcher = datamap.find(test_keys[i]);
    corr_values.push_back(searcher->second);
}

// printing the target data output
    /*vector<string>::iterator valprinter;
    int count=0;
    for(valprinter=corr_values.begin(); valprinter!=corr_values.end(); ++valprinter){
      cout<<++count<<". "<<*valprinter<<endl;
    }*/

// to find some particular key -------------------------- for debugging purpuse
    /*searcher = datamap.find("zzzaUE");
    cout<<"---------"<<endl;
    cout<<searcher->first<<", "<<searcher->second<<endl;*/

// ----------------------------- clocking part ---------------------------
end=clock();
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
cout<<fixed<<time_taken*1000000000<<endl;
cout<<"sec";

return 0;
}
