/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 july 2019
AIM    : use wide characters
STATUS : !!! success !!! basic things studied which all is required
##############################################################################*/

#include <iostream>
using namespace std;

/*
	Wide char is similar to char data type, except that wide char take up twice the space 
	and can take on much larger values as a result. char can take 256 values which corresponds
	to entries in the ASCII table. On the other hand, wide char can take on 65536 values which 
	corresponds to UNICODE values which is a recent international standard which allows for 
	the encoding of characters for virtually all languages and commonly used symbols.

	Just like the type for character constants is char, the type for wide character is 
	wchar_t.
	This data type occupies 2 or 4 bytes depending on the compiler being used.
	Mostly the wchar_t datatype is used when international languages like Japanese are used.

	- L is the prefix for wide character literals and wide-character string literals which 
	  tells the compiler that that the char or string is of type wide-char.
	- w is prefixed in operations like scanning (wcin) or printing (wcout) while operating 
	  wide-char type.
*/

int main(){

const char *a = "raghav gupta";
cout<<a<<" "<<sizeof(a)<<endl;

wchar_t w = L'w';
wcout<<w<<endl;
cout<<sizeof(w)<<endl;

wchar_t arr[] = L"mummy gupta";
wcout<<arr<<" "<<sizeof(arr)<<endl;

return 0;
}