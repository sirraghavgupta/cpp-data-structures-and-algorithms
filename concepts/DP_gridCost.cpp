/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 November 2019 
AIM    : to find the minimum cost to go from top left to bottom right node.
		 we can go only either rightwards or downwards.
		 no backward path possible.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int minGridCost(int grid[][100], int m, int n){
	int dp[100][100];

	dp[0][0] = grid[0][0];
	// fill the first col
	for(int i=1; i<m; i++)
		dp[i][0] = dp[i-1][0] + grid[i][0];

	// fill the first row 
	for(int j=1; j<n; j++)
		dp[0][j] = dp[0][j-1] + grid[0][j];

	// fill remaning grid
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
		}
	}

	// for testing purpose
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<setw(3)<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[m-1][n-1];

}	

int main(){

int m, n;
cin>>m>>n;

int arr[100][100];
for(int i=0; i<m; i++){
	for(int j=0; j<n; j++){
		cin>>arr[i][j];
	}
}

cout<<minGridCost(arr, m, n)<<endl;

return 0;
}

