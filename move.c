#include "defs.h"
#include<stdio.h>
#include<string.h>

/*
 *	input: 			string representing an L move
 *	output:			integer that corresponds to a L move
 *	description: 	This function translates from string representation of an
 *					L move to its respective integer representation.
 */
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

// #############################################################################

/*
 *	input: 			string representing a coin move
 *	output:			integer that corresponds to a coin move
 *	description: 	This function translates from string representation of a
 *					coin move to its respective inuteger representation.
 */
int parse_coinMove( const char *input ) {
	int result = OFFBOARD;
	int i = 0;
	
	for ( i = 0; i < 16; i++ ) {
		S_COINMOVE cmove = coinMoveLookupTable[i];
		if ( strcmp(cmove.key, input) == 0) {
			result = cmove.val;
			break;
		}
	}
	
	return result;
}

// #############################################################################

/*
 *	input: 			nothing
 *	output:			tuple of the integer representations of L and coin move
 *	description: 	This function prompts the user to input a move in stdin. 
 *					The string input is converted to the integer representation
 *					and is returned as the S_MOVE struct.
 */

// TODO:
// move has to actually get two positions for the coin (from, to) 
// - think about where the check for validity has to happen
// - think about placeholders for not moving it!?
S_MOVE get_move( void ) {
	S_MOVE result;
	char input[255];
	char inputL[5];
	char inputC[3];
	
	if ( fgets( input, sizeof input, stdin ) ) {
		input[ strcspn(input, "\n") ] = '\0';
	
		// copy first four elements of the input to inputL 
		// and add terminating char
		strncpy(inputL, input, 4);
		inputL[4] = '\0';
	
		// copy elements five and six to inputC and add terminating char
		strncpy(inputC, input+5, 2);
		inputC[2] = '\0';
	}
	else {
		printf( "ERROR: reading stdin\n" );
		ASSERT( FALSE );
	}
	
	result.lMove = parse_LMove( inputL );
	result.coinMove = parse_coinMove( inputC );
	return result;
}   	





    	
