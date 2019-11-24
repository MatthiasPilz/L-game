#include "defs.h"
#include<stdio.h>
#include<string.h>

int read_LMove( void ) {
	int result = NO_MOVE;
	char input[5];
	int i = 0;
	
	printf("Enter L move: ");
	if ( fgets( input, sizeof input, stdin ) ) {
    	input[ strcspn(input, "\n") ] = '\0';
    	
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
