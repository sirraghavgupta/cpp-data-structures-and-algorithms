/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 25 april 2019
AIM    : char array
         null character issue, initialization style, cout of char array,
          cin, cin.getline,
          read a paragraph by using cin.getline
          cin.get
STATUS : !!! doubts !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

/* if u dont specify the size of the array, u need to initialise it.
u can do this in two ways. by giving a list of charaters or by giving a string.

when, u initialise by list of characters, u need to add null character explicitly.
while in case of string method, it takes the null charcater automatically.

why null charcater? - to make it a string. it make easy to print. no need of loop
to print it. directly do cout<<arr. cout does that...  keeps on printing untill
it sees a null character. so,if ur char array doesnt contain a null character,
it will keep on printing the garbage values also which lie in the mem locs next
to your array [i.e. outside the array]. it might be garbage, it might be null.
so, u can get the actual string in output or the actual string + grabage values.

make it a rule to add a null char to your character arrays. or initialise by string.
*/

char a[] = {'a','b','c'};
cout<<a<<endl;         // prints garbage values also
cout<<sizeof(a)<<endl; // size=3 means that no null char inside the array

char b[]={'a','b','c','\0'};
cout<<b<<endl;
cout<<sizeof(b)<<endl; // now size=4 with null char

char c[] = "hello";
cout<<c<<endl;
cout<<sizeof(c)<<endl; //size=5[hello] + 1[null]

char d[100];
cin>>d;           //cin always reads a single word. stops at space.
cout<<d<<endl;

cout<<"-------"<<endl;

// fflush(stdin);     // to clear the input buffer
char e[100];
cin.getline(e,100);   // by def, getline stops at '\n'
cout<<e<<endl;

cout<<"--------"<<endl;

// to check for buffer only - whether req to clean or not.
char f[100];
cin>>f;
cout<<f<<endl;

cout<<"---------"<<endl;


// how to read a paragaph by using getline
char g[100];
cin.getline(g,100,'-');
cout<<g<<endl;

return 0;
}
