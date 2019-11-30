/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 November 2019 
AIM    : find the minimum number of steps required to reduce a number to 1
		 operations permited are - 
		 / by 3
		 / by 2
		 subtract 1
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;	// infinity 

int reduceNum_normal(int n){
	// without memoization, normal recursion
	// TC = O(3^n) - ver bad.
	// Base case
	if(n==1)
		return 0;

	// Rec Case
	int q1=inf, q2=inf, q3=inf;
	if(n%3 == 0)
		q1 = 1 + reduceNum_normal(n/3);
	if(n%2 == 0)
		q2 = 1 + reduceNum_normal(n/2);
	q3 = 1 + reduceNum_normal(n-1);

	int ans = min(q1, min(q2, q3));
	return ans;
}

int memo[10000];
int reduceNum_memoized(int n){
	// TC = O(N)

	// Base case
	if(n==1)
		return 0;

	// avoid recomputation 
	if(memo[n] != -1)
		return memo[n];

	// Rec Case
	int q1=inf, q2=inf, q3=inf;
	if(n%3 == 0)
		q1 = 1 + reduceNum_memoized(n/3);
	if(n%2 == 0)
		q2 = 1 + reduceNum_memoized(n/2);
	q3 = 1 + reduceNum_memoized(n-1);

	memo[n] = min(q1, min(q2, q3));
	return memo[n];
}

int reduceNum_pureDP(int n){
	// bottom up DP
	// TC = O(N)
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int num = 4; num<=n; num++){
		int q1=inf, q2=inf, q3=inf;

		if(num%3==0)
			q1 = 1+dp[num/3];
		if(num%2==0)
			q2 = 1+dp[num/2];
		q3 = 1+dp[num-1];

		dp[num] = min(q1, min(q2, q3));
	}
	return dp[n];
}

int main(){

int n;
cin>>n;

fill(memo, memo+n+1, -1);	// initialise the usable part of array to -1 initially. 

// cout<<reduceNum_normal(n)<<endl;
// cout<<reduceNum_memoized(n)<<endl;
cout<<reduceNum_pureDP(n)<<endl;

return 0;
}

