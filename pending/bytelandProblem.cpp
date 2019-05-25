/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 april 2019
AIM    : byteland problem
STATUS :
##############################################################################*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(int array[][4], int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<4; j++){
      cout<<array[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){

// ----------------------------------- clocking part ------------------------
clock_t start, end;
start=clock();

int n,q;        // n is the size of the byteland of nXnXn.
                // q is the number of queries
cin>>n>>q;

int qtype;            // type of query
unsigned long long int totPlayers=0;     // total number of players residing
unsigned long long int betweenPlayers=0; // players found between the specified range of query 2
unsigned long int query[q][4];      // to store only type 1 queries
int count=0;          //number of type1 queries


cout<<"i am ready please enter the queries now. "<<endl;

for(int i=0; i<q; i++){         // process all q queries one by one
  cin>>qtype;                   // get type of query in hand

  if(qtype==1){
    for(int j=0; j<4; j++){
      cin>>query[count][j];     // get the three coordinates x,y,z and the number of players
    }
    
    totPlayers+=query[count][3];
    cout<<"now, total players = "<<totPlayers<<endl;
    count++;

    printArray(query, count);     // check the contents of the query matrix
  }

  else{         // for processing type 2 queries 

    int x,y,z,X,Y,Z;      // starting and ending coordinates - range of searching 
    cin>>x>>y>>z>>X>>Y>>Z;

    betweenPlayers=0;     // initially answer=0 before search

    for(int k=0; k<count; k++){     // search the query matrix for required values
      if((query[k][0]>=x && query[k][0]<=X)&&(query[k][1]>=y && query[k][1]<=Y)&&(query[k][2]>=z && query[k][2]<=Z)){
        betweenPlayers+=query[k][3];
        cout<<"now, betweenPlayers = "<<betweenPlayers<<endl;
      }
    }

    cout<<"# -- for this query, answer = "<<totPlayers-betweenPlayers<<endl;

  }
cout<<"--------------------- next query ------------------------"<<endl;
}

end=clock();
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
cout<<fixed<<time_taken<<setprecision(5)<<endl;
cout<<"sec";
return 0;
}
