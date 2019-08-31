#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool comparator(const unordered_map<string, int> &a, const unordered_map<string, int> &b){

  string s1 = a.first, s2 = b.first;
  return strlen(a.first) > strlen(b.first);
}

int main(){

// ----------------------------------- clocking part ------------------------
clock_t start, end;
start=clock();



// empty map container
    unordered_map<string, int> datamap;
    ifstream fin;

// create the dataset in hashmap
    fin.open("words1.txt");
    string key, len;
    while(getline(fin,key)){
      // getline(fin,len);
      datamap.insert(pair<string, int>(key, key.length()));
    }
    fin.close();


// sorting the map according to length

    sort(datamap.begin(), datamap.end(), comparator);


// printing map datamap
        unordered_map<string, int>::iterator mapprinter;
        int count=0;                                  // print only 100 lens
        cout << "KEY\tLENGTH\n";
        // mapprinter!=datamap.end()
        for (mapprinter = datamap.begin(); count<100; ++mapprinter) {
            cout << mapprinter->first<<'\t'
                 << mapprinter->second << '\n';
            count++;
        }
        cout << endl;


/*
// create the test data in string vector
    vector<string> test_keys;
    fin.open("test.txt");
    while(fin>>key){
      test_keys.push_back(key);
    }
    fin.close();
*/


// print the test data
  /*int count=0;
  vector<string>::iterator keyprinter;
    for(keyprinter=test_keys.begin(); keyprinter!=test_keys.end(); ++keyprinter){
      cout<<++count<<". "<<*keyprinter<<endl;
    }*/

/*
// lookup for lens
vector<string> corr_lens;                 // to hold the output lens
map<string, string>::iterator searcher;
for(int i=0; i<test_keys.size(); i++){
    searcher = datamap.find(test_keys[i]);
    corr_lens.push_back(searcher->second);
}*/

// printing the target data output
    /*vector<string>::iterator valprinter;
    int count=0;
    for(valprinter=corr_lens.begin(); valprinter!=corr_lens.end(); ++valprinter){
      cout<<++count<<". "<<*valprinter<<endl;
    }*/

// to find some particular key -------------------------- for debugging purpuse
    /*searcher = datamap.find("zzzaUE");
    cout<<"---------"<<endl;
    cout<<searcher->first<<", "<<searcher->second<<endl;*/

// ----------------------------- clocking part ---------------------------
end=clock();
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
cout<<fixed<<time_taken<<endl;
cout<<"sec";

return 0;
}
