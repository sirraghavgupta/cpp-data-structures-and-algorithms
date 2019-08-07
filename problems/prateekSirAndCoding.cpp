/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 august 2019
AIM    : see shots
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <stack>
using namespace std;

int main(){

stack<int> s;
int q;
cin>>q;

int type, cost;
while(q--){
	cin>>type;

	switch(type){
		case 1:
				if(s.empty())
					cout<<"No Code"<<endl;
				else{
					cout<<s.top()<<endl;
					s.pop();
				}
				break;
		case 2:
				cin>>cost;
				s.push(cost);
				break;
	}
}

return 0;
}