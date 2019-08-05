#include <stdio.h>
void main(){

	// q3
	/*int var = 0;
	for( ; var++; var++);
	printf("%d", var);

	// here it enters the loop but as it checks the condition, its says (var++) which says use me first
	   and then increment. so, now 0 is there -> condtion false -> exit from loop -> value already incred
	   ->prints 1; --->done = good question 
	*/

	// q4
	/*int i;
	printf("enter the value of i ");
	scanf("%d", &i);
	if(i<7){
		{
			i++;
			continue;
		}
		printf("final value of i is :%d", i);

	// can use continue in looping only.
	}*/

	//q6
	/*int i, j=0;
	for(i=0, j=0; i<5, j<25; i++, j++);
	printf("%d, %d\n", i, j);
	
	// it means that its taking the OR of the 2 conditions
	*/


	//q8
	int num;
	printf("enter a number\n");
	scanf("%d", &num);
	if(num%2 == 0)
		goto even;
	else
		printf("the number is odd\n");
	even:
	printf("the number is even\n");

}