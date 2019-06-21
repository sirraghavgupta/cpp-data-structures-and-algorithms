/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 june 2019
AIM    : Given three numbers a,b,c. Calculate (a^b)mod c.
STATUS : ---------------- I N C O M P L E T E ----------------
##############################################################################*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){

double a,b,c;
cin>>a>>b>>c;

long long int result = pow(a,b);
cout<<result<<endl;
return 0;
}