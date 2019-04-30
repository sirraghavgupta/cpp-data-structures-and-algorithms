/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 april 2019
AIM    : to tokenise a string by using inbuilt function of cstring header
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cstring>
using namespace std;

int main(){

char str[100] = "hi!, i am raghav gupta. practicing and learning c++.";
char *ptr; // its mist to create a dangling pointer first.

ptr=strtok(str, "!., ");
  // cout<<ptr<<endl;       to print the token
/*
parameter 1 - a C style string
parameter 2 - a continous string of all the delimiters u want
return to a pointer

 - in one time, it returns only one token
 - next time u run the function on the same string, u get the same answer
 - because the way to use is: pass the string only for the first time. for
   further calls, pass a null pointer there. and it will give u the next token

how it works? -
  -  a static variable is there inside it, which stores the state of the string
  - so next time u dont need to pass the string, it automatically does the work
    on the same string
  - if u pass the string again, the state gets reset and it gives the same answer
    again.
  - when the string ends, it returns a NULL pointer.
 */

 /**/

while(ptr!=NULL){       // to check if null is not returned
  cout<<ptr<<endl;      // print the token recieved
  ptr=strtok(NULL, "!., ");     // look for next token
            /* passing null signifies that keep working on the same string and
               from where u left off in last call */
}


return 0;
}
