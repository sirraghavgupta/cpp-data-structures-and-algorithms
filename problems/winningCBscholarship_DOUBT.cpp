/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 june 2019
AIM    : there are n students. we want to give scholarship to maximum students
	     but not cause any loss to the organisation.
	     we have m free coupons in beginning.
	     a test will be conducted and performnace recorded
	     anybody will get the scholarship if he has gathered x coupons
	     those who will not perform well in the exam will have to pay for
	     y coupons.
	     so, we get the amount from those who dont perform well, plus we have 
	     some initial amount. this way we have to maximise the number of students
	     who will get the scholaship.
APPROACH : ----- DIVIDE AND CONQUER -----------
				--------- BINARY SEARCH --------------
STATUS : !!! !!!
##############################################################################*/

#include <iostream>
#define ll long long int
using namespace std;

int findScholarship(int n, int m, int x, int y){
	int start=0, end=n;
	int ans=0;
	while(start<=end){
		int mid=(start+end)/2;
		ll have = m + (n-mid)*y;
		cout<<"have = "<<have<<endl;
		ll cost = mid*x;
		cout<<"cost = "<<cost<<endl;
		if(have>=cost){
			ans=mid;
			start=mid+1;
		}
		else end=mid-1;
	}
	return ans;
}

int main(){

int n, m, x, y;
cin>>n>>m>>x>>y;

cout<<findScholarship(n, m, x, y)<<endl;

return 0;
}