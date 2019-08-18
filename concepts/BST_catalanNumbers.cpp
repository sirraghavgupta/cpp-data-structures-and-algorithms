/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 16 august 2019
AIM    : to calculate the catalan number by recursion - convert into dp
		 there are 3 ways - 
		 	* recursion - time consuming
		 	* dp - fast
		 	* formula direct
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

/*
// recursion -----
int catalan(int n){	
	// base case
	if(n==0)
		return 1;
	// rec case
	int sum=0;
	for(int i=1; i<=n; i++){
		sum+=catalan(i-1)*catalan(n-i);
	}
	return sum;
}*/

// convert into DP -----
int dp[100] =  {0};
int catalan(int n){	

// in recursion, the same catalan number was being evaluated again n again.
// so, we vanish the repetition of solving the same problem
// this is dynamic programming.

	// base case
	if(n==0)
		return 1;

	// rec case
	if(dp[n])
		return dp[n];

	int sum=0;
	for(int i=1; i<=n; i++){
		sum+=catalan(i-1)*catalan(n-i);
	}
	// if its calculated for the first time, then store it
	dp[n]=sum;
	return sum;
}

int main(){
for(int i=0; i<5; i++){
	cout<<catalan(i)<<endl;
}
return 0;
}