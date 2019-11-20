/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 4 november 2019 
AIM    : to implement flood fill coloring algorithm for graphs 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int r, c;

// ch is the character to be replaced 
// color is the color to be filled 
void floodfill(char input[][50], int x, int y, char ch, char color){
	// base case for matrix boundary 
	if(x<0 || y<0 || x>=r || y>=c)
		return;

	// figure boundary conmdition 
	if(input[x][y] != ch || input[x][y]==color)
		return;

	// recursive case 
	if(input[x][y] != color){
		input[x][y] = color;
		floodfill(input, x+1, y, ch, color);
		floodfill(input, x-1, y, ch, color);
		floodfill(input, x, y+1, ch, color);
		floodfill(input, x, y-1, ch, color);
	}
}

int main(){

cin>>r>>c;

char input[15][50];

for(int i=0; i<r; i++){
	for(int j=0; j<c; j++){
		cin>>input[i][j];
	}
}

floodfill(input, 8, 13, '.', 'o');
floodfill(input, 2, 14, '.', 'g');

for(int i=0; i<r; i++){
	for(int j=0; j<c; j++){
		cout<<input[i][j];
	}
	cout<<endl;
}

return 0;
}

