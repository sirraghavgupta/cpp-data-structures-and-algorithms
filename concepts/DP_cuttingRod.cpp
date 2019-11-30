/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 November 2019 
AIM    : given a rod of length n.
		 price is given for every length of rod. 
		 we have to cut the rod in such a way that we can get maximum profit.
		 find the maximum profit. 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int maxProfit_normal(int price[], int lengthOfRod){
	// TC = O(N^N)
	cnt++;
	// base case 
	if(lengthOfRod==0)
		return 0;

	// Rec case
	int netProfit = 0;
	for(int cut = 1; cut<=lengthOfRod; cut++){
		int ans = price[cut] + maxProfit_normal(price, lengthOfRod-cut);
		netProfit = max(netProfit, ans);
	}
	return netProfit;
}

int memo[100];
int maxProfit_memoized(int price[], int lengthOfRod){
	// TC = O(n^2)
	// base case 
	cnt++;
	if(lengthOfRod==0)
		return 0;

	// Rec case
	if(memo[lengthOfRod]!=-1)
		return memo[lengthOfRod];

	int netProfit = 0;
	for(int cut = 1; cut<=lengthOfRod; cut++){
		int ans = price[cut] + maxProfit_memoized(price, lengthOfRod-cut);
		netProfit = max(netProfit, ans);
		// cout<<cnt<<endl;
	}
	memo[lengthOfRod] = netProfit;
	return netProfit;
}

int maxProfit_pureDP(int price[], int len){
	int dp[100];
	dp[0] = 0;
	dp[1] = price[1];

	for(int l=2; l<=len; l++){
		int best = 0;
		for(int cut=1; cut<=l; cut++){
			int netProfit = price[l-cut] + price[cut];
			best = max(netProfit, best);
		}
		dp[l] = best;
	}
	return dp[len];
}

int main(){

int len;
cin>>len;
	
int price[100];
for(int l=1; l<=len; l++){
	cin>>price[l];
}
price[0] = 0;
memset(memo, -1, sizeof(memo));

// cout<<maxProfit_normal(price, len)<<endl;
// cout<<maxProfit_memoized(price, len)<<endl;
cout<<maxProfit_pureDP(price, len)<<endl;

// cout<<cnt<<endl;

return 0;
}

