/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 april 2019
AIM    : daily code byte ----- write later
STATUS :
##############################################################################*/
#include <iostream>
// #include <stdio.h>
#include <cstring>
using namespace std;

int main(){

int n, q;    // n is the size of the nxnxn namespace
             // q is the number of queries
int totPlayers=0;     // total players of all the contingents
                      // or the total number of residents

cin>>n;
cin>>q;
int space[n+1][n+1][n+1];
memset(space, 0, (n+1)*(n+1)*(n+1)*sizeof(int));

/*int count=1;
for(int i=0;  i<n+1; i++){
  for(int j=0; j<n+1; j++){
    for(int k=0; k<n+1; k++){
      cout<<count<<". "<<space[i][j][k]<<endl;
      count++;
    }
  }
}*/

for(int l=0; l<q; l++){       // process the queries one by one
  int qtype, x, y, z, X, Y, Z;
  int val;
      // qtype is the type of query - 1/2
      // x,y,z is the coordinates of hotel w.r.t. qtype=1
      // x,y,z is the starting range of hotel search w.r.t. qtype=2
      // X,Y,Z is the ending range of hotel search w.r.t. qtype=2

  cin>>qtype;     // get query type

  if(qtype==1){   // process type 1 query
    cin>>x>>y>>z>>val;
    space[x][y][z]=val;     // accomodate the contingent
    totPlayers+=val;        // update total numner of players
    // cout<<"space[x][y][z] = "<<space[x][y][z]<<endl;
    // cout<<"totPlayers = "<<totPlayers<<endl;
  }

  else{           // process type 2 query
    int betPlayers=0;       // answer of type 2 query
    cin>>x>>y>>z>>X>>Y>>Z;

    // perform counting in the space specified
    for(int i=x;  i<X+1; i++){
      for(int j=y; j<Y+1; j++){
        for(int k=z; k<Z+1; k++){
          if(space[i][j][k]!=0){
            // cout<<"intially betPlayers = "<<betPlayers<<endl;
            // cout<<"value seen = "<<space[i][j][k]<<endl;
            betPlayers+=space[i][j][k];     // evaluate answer
            // cout<<" now betPlayers = "<<betPlayers<<endl;
          }
        }
      }
    }
    // cout<<"final answer = "<<totPlayers-betPlayers<<endl;
    cout<<totPlayers-betPlayers<<endl;
  }
}
return 0;
}
