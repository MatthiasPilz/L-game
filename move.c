#include "defs.h"
#include<stdio.h>
#include<string.h>

/*
 *	input: 			string representing an L move
 *	output:			populated S_LMOVE struct
 *	description: 	This function translates from string representation of an
 *					L move to its respective integer representation.
 */
S_LMOVE parse_LMove( char *input ) {
	int i = 0;
	S_LMOVE result = { .lPos = {input, NO_MOVE} };
	
    for ( i = 0; i < 48; i++ ) { 
    	S_DICT curMove = LMoveLookupTable[i];
       	if (strcmp(curMove.key, input) == 0) {
           	//result.lPos.key = curMove.key;
           	result.lPos.val = curMove.val;
           	break;
       	}
    }
	
	return result;
}

// #############################################################################

/*
 *	input: 			string representing a coin move
 *	output:			populated S_COINMOVE struct
 *	description: 	This function translates from string representation of a
 *					coin move to its respective integer representation.
 */
S_COINMOVE parse_coinMove( char *input ) {
	// initialising variables
	char inputFrom[3];
	char inputTo[3];
	int i = 0;
	S_DICT curMove = { .key = "--", .val = OFFBOARD };
	
	// splitting input into two parts (and add terminating chars)
	strncpy(inputFrom, input, 2);
	strncpy(inputTo, input+2, 2);
	inputFrom[2] = '\0';
	inputTo[2] = '\0';
	
	// initalise struct to be returned
	S_COINMOVE result = { 	.from = {inputFrom, OFFBOARD}, 
							.to = {inputTo, OFFBOARD} 		};
	
	// loop for both inputs separately
	for ( i = 0; i < 16; i++ ) {
		curMove = coinMoveLookupTable[i];
		if ( strcmp(curMove.key, inputFrom) == 0) {
			result.from.val = curMove.val;
			break;
		}
	}
	
	for ( i = 0; i < 16; i++ ) {
		curMove = coinMoveLookupTable[i];
		if ( strcmp(curMove.key, inputTo) == 0) {
			result.to.val = curMove.val;
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
S_MOVE get_move( void ) {
	S_MOVE result;
	char input[255];
	char inputL[5];
	char inputC[5];
	
	if ( fgets( input, sizeof input, stdin ) ) {
		input[ strcspn(input, "\n") ] = '\0';
	
		// copy first four elements of the input (0,1,2,3) to inputL 
		// and add terminating char
		strncpy(inputL, input, 4);
		inputL[4] = '\0';
	
		// copy four elements (5,6,7,8) to inputC and add terminating char
		strncpy(inputC, input+5, 4);
		inputC[4] = '\0';
	}
	else {
		printf( "ERROR: reading stdin\n" );
		ASSERT( FALSE );
	}
	
	result.lMove = parse_LMove( inputL );
	result.coinMove = parse_coinMove( inputC );
	return result;
}   	





    	
