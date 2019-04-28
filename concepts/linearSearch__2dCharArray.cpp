/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 april 2019
AIM    : implement linear search on 2d char array
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cstring>
using namespace std;

void linearSearch(char arr[][100], int n, char key[]){
  // search a string in 2d char array
    for(int i=0; i<n; i++){
      if(!strcmp(key,arr[i])){
        cout<<"key found at index "<<i<<endl;
        return;
      }
    }
  cout<<"key not found"<<endl;
  return;
}

int main(){

char fruits[10][100];
int n;
cin>>n;
cin.ignore();     //to ignore the \n afte entering the value of n
                  // must to use before getline if u had taken another value also
                  // because cin doesnt take special characters, so they r stray

// string input
for(int i=0; i<n; i++){
  cin.getline(fruits[i], 100);
}

// string output/ display
for(int i=0; i<n; i++){
  cout<<i<<". "<<fruits[i]<<endl;
}

// linear search
char key[100];
cin.getline(key, 100);
linearSearch(fruits, n, key);


return 0;
}
