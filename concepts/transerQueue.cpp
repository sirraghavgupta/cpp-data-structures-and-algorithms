/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 25 july 2019
AIM    : transfer n-1 elements fron one queue to another
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
using namespace std;

void transfer(queue<int> &q1, queue<int> &q2){
	int n = q1.size();	// get the size of queue
	cout<<n<<endl;
	while(n>1){
		int data = q1.front();
		q1.pop();
		q2.push(data);
		n--;
	}
}

int main(){

queue<int> q1, q2;

// push elements into queue.
for(int i=1; i<6; i++){
	q1.push(i*i);
}

transfer(q1, q2);

// print q1
while(!q1.empty()){
	cout<<q1.front()<<" ";
	q1.pop();
}
cout<<endl;
// print q2
while(!q2.empty()){
	cout<<q2.front()<<" ";
	q2.pop();
}
cout<<endl;

return 0;
}