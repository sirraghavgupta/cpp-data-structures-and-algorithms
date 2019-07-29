/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 july 2019
AIM    : The stock span problem is a financial problem where we have a series of 
		 N daily price quotes for a stock and we need to calculate span of 
		 stock’s price for all N days. You are given an array of length N, where 
		 ith element of array denotes the price of a stock on ith. Find the span 
		 of stock's price on ith day, for every 1<=i<=N.
		 A span of a stock's price on a given day, i, is the maximum number of 
		 consecutive days before the (i+1)th day, for which stock's price on 
		 these days is less than or equal to that on the ith day.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int arr[], int n){
	stack<int> s;  // stores the latest biggest element after every iteration 
	int span[n];   // stores the answers
	for(int day=0; day<n; day++){	// for all days
		int currPrice = arr[day];   

		// reach the target day
		while(!s.empty() && arr[s.top()]<currPrice){
			s.pop();
		}

		// if stack empty, u r the biggest, so span = 0;
		// else calculate the diffrence b|w the biggest and current
		int betterday = s.empty()?day:s.top();
		int spn = day - betterday;
		span[day] = spn;
		s.push(day);	// push current day as smaller value days may come further
	}


	// print the span
	for(int i=0; i<n; i++)
		cout<<span[i]<<" ";
	cout<<endl;
	return;
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

stockSpan(arr, n);

return 0;
}