/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 june 2019
AIM    : to study the functioning of command line argumens in c
STATUS : !!! success !!!
##############################################################################*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){  // argc stores the number of argumentss automatically
								   // argv is the argument values array	
	if(argc<2){		// because there is always and always one command line arg
					// called as default argument stored in argv[0]
		printf("no arguments\n");
		return 1;
	}

	for(int i=1; i<argc; i++){	// start from 1 always
		printf("arg[%2d]: %d\n", i, atoi(argv[i]));
	}

	return 0;
}