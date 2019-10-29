/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 October 2019 
AIM    : solve the travelling salesman problem by using DP iwth bitmasks
TIME   : O(2^n * n)
STATUS : !!! success !!!   very diff 
##############################################################################*/

#include <iostream>
using namespace std;

#define INT_MAX 999999;

int n=4;		// 4 cities 
int dp[16][4];
int dist[10][10] = {{0, 20, 42, 25},
					{20, 0, 30, 34},
					{42, 30, 0, 10},
					{25, 34, 10, 0}};

int VISITED_ALL = (1<<n) - 1;	// mask that represents all cities visited.  

int tsp(int mask, int pos){
	// get the mask for the path traversed 
	// get the current position city 

	if(mask == VISITED_ALL){
		//if all cities have been visited till yet. 
		return dist[pos][0];
	}

	// lookup
	if(dp[mask][pos] != -1){
		return dp[mask][pos];
	}

	int ans = INT_MAX;
	// try to go to an unvisited city
	for(int city=0; city<n; city++){

		if((mask&(1<<city)) == 0){	// if unvisited city 

			int newAns = dist[pos][city] + tsp(mask|(1<<city), city);
				// distance from the current city to next choosen city 
				// + the minimum distance from there by recursion  

			ans = min(ans, newAns);	// ge minimum distance from all options available from current pos 
		}
	}

	return dp[mask][pos] = ans;
}

int main(){

// initial setup of DP array 
for(int i=0; i<(1<<n); i++){
	for(int j=0; j<n; j++)
		dp[i][j] = -1;
}

cout<<tsp(1, 0)<<endl;

return 0;
}

