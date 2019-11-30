/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 November 2019 
AIM    : to generate maximum profit by selling the wine bottles.
		 we can sell bottles from extreme ends only.
		 older wine is expensive.
		 so, SP of wine is the price * year in which its sold.
		 see the shots for more info.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int cnt=0;	// counts the number of recursive calls 
int memo[100][100];

int maxProfit_normal(int arr[], int beg, int end, int year){
	// normal solution
	// TC = O(2^n)
	cnt++;

	if(beg > end)
		return 0;

	int q1 = arr[beg]*year + maxProfit_normal(arr, beg+1, end, year+1);
	int q2 = arr[end]*year + maxProfit_normal(arr, beg, end-1, year+1);
	int ans = max(q1, q2);
	// cout<<"("<<beg<<","<<end<<") -> "<<ans<<endl;
	return ans;
}

void printMemo(){
	// just for understanding the flow of concept.  
	int n = 5;
	cout<<"------------"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<memo[i][j]<<" ";
		}
		cout<<endl;
	}
}

int maxProfit_memoized(int arr[], int beg, int end, int year){
	// top down DP
	// TC = O(n^2)
	cnt++;

	if(beg > end)
		return 0;

	if(memo[beg][end] != -1)	return memo[beg][end];		// avoid recomputation 

	int q1 = arr[beg]*year + maxProfit_memoized(arr, beg+1, end, year+1);
	int q2 = arr[end]*year + maxProfit_memoized(arr, beg, end-1, year+1);
	memo[beg][end] = max(q1, q2);
	// printMemo();
	return memo[beg][end];
}

int maxProfit_pureDP(int arr[], int n){
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	int year = n;

	// fill for the last year - only 1 bottle left. 
	for(int i=0; i<n; i++){
		dp[i][i] = year * arr[i];
	}
	year--;

	// ---------------------------
	/*cout<<"------------"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	// ---------------------------

	// fill for the other years. len = number of bottles 
	for(int len = 2; len<=n; len++){
		
		int startRow = 0, endRow = n-len;
		for(int i = startRow; i<=endRow; i++){
			int q1 = arr[i]*year + dp[i+1][i+len-1];
			int q2 = arr[i+len-1]*year + dp[i][i+len-2];
			int ans = max(q1, q2);
			dp[i][i+len-1] = ans;
		}
		year--;

	// ---------------------------
	/*cout<<"------------"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<setw(3)<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	// ---------------------------

	}


	return dp[0][n-1];
}

int main(){

int n;	// no. of bottles 
cin>>n;

int arr[100];	// store the prices of wines. 
for(int i=0; i<n; i++){
	cin>>arr[i];
}

memset(memo, -1, sizeof(memo));

// cout<<maxProfit_normal(arr, 0, n-1, 1)<<endl;
// cout<<maxProfit_memoized(arr, 0, n-1, 1)<<endl;
cout<<maxProfit_pureDP(arr, n)<<endl;
// cout<<cnt<<endl;

return 0;
}

