/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 september 2019
AIM    : Dean of MAIT is going to visit Hostels of MAIT. As you know that he is 
		 a very busy person so he decided to visit only first "K" nearest Hostels. 
		 Hostels are situated in 2D plane. You are given the coordinates of 
		 hostels and you have to answer the Rocket distance of Kth nearest hostel 
		 from origin ( Dean's place ) .
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int main(){

priority_queue<long long int> pq;
int size=0;

int q, k;	// q = number of queries
cin>>q>>k;

long long int distance;
while(q--){
	int qtype;
	cin>>qtype;

	switch(qtype){
		case 1:
				long long int x,y;
				cin>>x>>y;
				distance = x*x + y*y;
				if(size<k){
					pq.push(distance);
					size++;
				}
				else{
					if(distance<pq.top()){
						pq.pop();
						pq.push(distance);
					}
				}
				break;
		case 2:
				cout<<pq.top()<<endl;
				break;

	}
}

return 0;
}