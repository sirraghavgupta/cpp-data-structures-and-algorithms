/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 25 april 2019
AIM    : char array
         null character issue, initialization style, cout of char array,
          cin, cin.getline,
          read a paragraph by using cin.getline
          cin.get
STATUS :
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

char a[] = {'a','b','c'};
cout<<a<<endl;
cout<<sizeof(a)<<endl;

char b[]={'a','b','c','\0'};
cout<<b<<endl;
cout<<sizeof(b)<<endl;

char c[] = "hello";
cout<<c<<endl;
cout<<sizeof(c)<<endl;

char d[100];
cin>>d;
cout<<d<<endl;

cout<<"-------"<<endl;

fflush(stdin);
char e[100];
cin.getline(e,100);
cout<<e<<endl;

cout<<"--------"<<endl;

char f[100];
cin>>f;
cout<<f<<endl;

cout<<"---------"<<endl;

char g[100];
cin.getline(g,100,'-');
cout<<g<<endl;

return 0;
}
