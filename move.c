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
// TODO
// - change this to 'parse L move'
// - add 'parse coin move'
// - use them in 'get move' function
int parse_LMove( const char *input ) {
	int result = NO_MOVE;
	int i = 0;
	
    for ( i = 0; i < 48; i++ ) {
       	S_LMOVE lmove = LMoveLookupTable[i];
       	if (strcmp(lmove.key, input) == 0) {
           	result = lmove.val;
           	break;
       	}
    }
	
	return result;
}

int parse_coinMove( const char *input ) {
	int result = OFFBOARD;
	int i = 0;
	
	for ( i = 0; i < 16; i++ ) {
		// TODO
		// - create coin move struct
		// - create coin move lookup table
		// - compare key to input (same as in parse_LMove)
	}
	
	return result;
}

// TODO
S_MOVE get_move( void ) {
	S_MOVE result;
	return result;
}
/*
	// MAYBE USED LATER...
	if ( fgets( input, sizeof input, stdin ) ) {
    	input[ strcspn(input, "\n") ] = '\0';
    	
    	// TODO
    	// without this getchar(); the line "Enter L move" is printed twice..
    	// don't know yet how to get around it..
    	getchar();
*/    	
    	
