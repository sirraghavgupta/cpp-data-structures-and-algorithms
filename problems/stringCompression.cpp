/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : Take as input S, a string. Write a function that does basic string 
		 compression. Print the value returned. E.g. for input "aaabbccds" print 
		 out a3b2c2d1s1.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

char str[101];
cin>>str;				// get the string

char newString[201];	// target string double the size of input string if no 
						// consecutive characters are same

int i=0, count=1;		// i points to initial string
						// count is the count of any charcater
int length = strlen(str);

int j=0;				// j points to the new string
while(i<length){
	if(str[i] == str[i+1])	// if chars are same, then increment count
		count++;

	else{					// else update in the target string and prepare for next character

		newString[j]=str[i];
		j++;

		if(count<10)
			newString[j]=char(48+count);

		else {		// push 2 digit count in the string
			int r=count%10;		// remainder
			count/=10;			// quotient
			newString[j]=char(48+count);	// push quotient first
			j++;
			newString[j]=char(48+r);		// push remainder
		}

		j++;	
		count=1;

	}

i++;
}

newString[j]='\0';		// terminate the string by null
cout<<newString<<endl;
return 0;
}