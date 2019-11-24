#include "defs.h"
#include<stdio.h>
#include<string.h>

/*
 *	input: 			nothing
 *	output:			integer that corresponds to a L position
 *	description: 	This function prompts the user to enter a L position.
 *					It is translated to its respective integer representation 
 *					and the integer is returned.
 */
int read_LMove( void ) {
	int result = NO_MOVE;
	char input[255];
	int i = 0;
	
	printf("Enter L move: ");
	if ( fgets( input, sizeof input, stdin ) ) {
    	input[ strcspn(input, "\n") ] = '\0';
    	
    	// TODO
    	// without this getchar(); the line "Enter L move" is printed twice..
    	// don't know yet how to get around it..
    	getchar();
    	
    	for ( i = 0; i < 48; i++ ) {
        	S_LMOVE lmove = LMoveLookupTable[i];
        	if (strcmp(lmove.key, input) == 0) {
            	result = lmove.val;
            	break;
        	}
    	}
	} 
	else {
    	printf( "Something bad happened\n" );
	}

	return result;
}
