/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 july 2019
AIM    : to implement queue using STL.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
using namespace std;

int main(){

queue<int> q;

for(int i=1; i<6; i++){
	q.push(i*i);
}

while(!q.empty()){
	cout<<q.front()<<" ";
	q.pop();
}
cout<<endl;
return 0;
}