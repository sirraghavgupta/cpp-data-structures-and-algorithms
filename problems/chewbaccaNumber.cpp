/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 june 2019
AIM    : Help Chewbacca to transform the initial number x to the minimum possible positive 
         number by inverting some (possibly, zero) digits. The decimal representation of the 
         final number shouldn't start with a zero.
         example - 
         4545 ==> 4444
         9456 ==> 9443
         inverting means complimenting the digits with 9
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

unsigned long long int complimentDigits(unsigned long long int number){
    short int digit=0;
    unsigned long long int result=0, numcopy=number, count=1;
    // count hold the place value of the digit to be added to the number
    // result is the intermediate result at any time
    // numcopy is the copy of number to help in operating

    while(number>0){
        digit=number%10;    // get the digits

        if(digit>9-digit){  // if compliment is required
            result+=(9-digit)*count;
        }
        else{
            result+=digit*count;
        }
        number/=10;          // prepare number for next use
        count*=10;           // prepare count  for next use
    }

    count/=10;                // now it becomes the face value of first digit in number
    if(numcopy/count == 9){   // if the first digit was 9
        result+=9*count;    
    }

return result;
}

int main() {
    unsigned long long int number;
    cin>>number;
    cout<<complimentDigits(number)<<endl;

return 0;
}
