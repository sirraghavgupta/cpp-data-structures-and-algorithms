/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 october 2019
AIM    : u are given an array of indian currency coins and a value
		 tell the minimum number of coins required to exchange the value.
STATUS : !!! complete - NOT EVALUATED  !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int getMinCoins(int value, int coins[], int n){

	if(value==0)
		return 0;

	int i;
	for(i=0; i<n; i++){
		if(coins[i]>value){
			break;
		}
	}
	value -= coins[i-1];
	return 1+getMinCoins(value, coins, n);
}

int main(){

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
int n = sizeof(coins)/sizeof(int);

sort(coins, coins+n);	// increasing order of denomination 

int value;
cin>>value;

cout<<getMinCoins(value, coins, n)<<endl;


return 0;
}