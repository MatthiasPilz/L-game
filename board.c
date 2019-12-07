#include "defs.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// #############################################################################

/*
 *	input: 			S_POSITION struct *pos
 *	output:			none (updates pos)
 *	description: 	All fields that make up the actual playing area are declared
 *					EMPTY, and all the other fields are declared OFFBOARD.
 */
void reset_board(S_POSITION *pos) {
	// initialise variables
	int index = 0;
	int rank = RANK_1;
	int file = FILE_A;

	// loop through entire board and set everything to OFFBOARD
	for(index = 0; index < BOARD_SQ_NUM; ++index) {		
		pos->board[index] = OFFBOARD;
	}

	// loop through ranks and files of the actual playing area
	for(rank = RANK_1; rank <= RANK_4; ++rank) {
		for(file = FILE_A; file <= FILE_D; ++file) {
			pos->board[FR2SQ(file,rank)] = EMPTY;
		}
	}
	
	pos->whiteL = NO_MOVE;
	pos->blackL = NO_MOVE;
	pos->coins[0] = OFFBOARD;
	pos->coins[1] = OFFBOARD;
}

// #############################################################################

/*
 *	input: 			S_POSITION struct *pos
 *	output:			none (prints to stdout)
 *	description: 	Prints the current board to the terminal.
 * 					Rank number is on the left of the board and file name on
 *					bottom.
 */
void print_board( const S_POSITION *pos ) {
	// initialise variables
	int sq = OFFBOARD;
	int file = FILE_NONE;
	int rank = RANK_NONE;
	int piece = EMPTY;
	
	printf("   ---------------   \n");
	for(rank = RANK_4; rank >= RANK_1; rank--) {
		printf("%d | ",rank+1);
		for(file = FILE_A; file <= FILE_D; file++) {
			sq = FR2SQ(file,rank);
			piece = pos->board[sq];
			printf("%c | ",PceChar[piece]);
		}
		if ( rank != RANK_1 ) {
			printf("\n  |---------------|  \n");
		}
	}
	
	printf("\n   ---------------   \n ");
	for(file = FILE_A; file <= FILE_D; file++) {
		printf("%4c", FileChar[file]);
	}
	printf("\n\n");
	printf("side: %c\n",SideChar[pos->side]);
}

// #############################################################################

/*
 *	input: 			S_POSITION struct *pos
 *	output:			none (updates pos)
 *	description: 	Write the positions of white and black L and the coins
 *					on the board. The previous board is not erased.
 */
void update_board( S_POSITION *pos ) {
	// initialise variables
	int cornerWhiteL = OFFBOARD;
	int cornerBlackL = OFFBOARD;
	int direction = NO_DIR;
	
	
	// WHITE PIECE
		// corner piece
	if ( pos->whiteL >= 0 && pos->whiteL < NO_MOVE ) { 
		cornerWhiteL = LPosFields[pos->whiteL];
		pos->board[cornerWhiteL] = wL;
	
		// long side
		direction = LongSideDirection[pos->whiteL];
		pos->board[cornerWhiteL + direction] = wL;
		pos->board[cornerWhiteL + 2*direction] = wL;

		// short side
		direction = ShortSideDirection[pos->whiteL];
		pos->board[cornerWhiteL + direction] = wL;
    }
    
    // BLACK PIECE
    	// corner piece
	if ( pos->blackL >= 0 && pos->blackL < NO_MOVE ) { 
		cornerBlackL = LPosFields[pos->blackL];
		pos->board[cornerBlackL] = bL;

		// long side
		direction = LongSideDirection[pos->blackL];
		pos->board[cornerBlackL + direction] = bL;
		pos->board[cornerBlackL + 2*direction] = bL;
	
		// short side
		direction = ShortSideDirection[pos->blackL];
		pos->board[cornerBlackL + direction] = bL;
    }
    
    // COINS
	if ( pos->coins[0] != OFFBOARD ) {
		pos->board[pos->coins[0]] = cN;
	}
	
	if ( pos->coins[1] != OFFBOARD ) {
		pos->board[pos->coins[1]] = cN;
	}
}

// #############################################################################

/*
 *	input: 			string representing an L position
 *	output:			integer representation of position
 *	description: 	This function translates from string representation of an
 *					L position to its respective integer representation.
 */
int parse_integerOfL( char *input ) {
	int i = 0;
	int result = NO_MOVE;
	
    for ( i = 0; i < 48; i++ ) { 
    	S_DICT curMove = LMoveLookupTable[i];
       	if (strcmp(curMove.key, input) == 0) {
           	result = curMove.val;
           	break;
       	}
    }
	
	return result;
} 

// #############################################################################

/*
 *	input: 			string representing a coin position
 *	output:			integer representation of position
 *	description: 	This function translates from string representation of a
 *					coin position to its respective integer representation.
 */
int parse_integerOfCoin( char *input ) {
	int i = 0;
	int result = OFFBOARD;
	
    for ( i = 0; i < 48; i++ ) { 
    	S_DICT curMove = coinMoveLookupTable[i];
       	if (strcmp(curMove.key, input) == 0) {
           	result = curMove.val;
           	break;
       	}
    }
	
	return result;
} 

// #############################################################################

/*
 *	input: 			position 
 *	output:			none (updates position)
 *	description: 	Read position string from command line and parse it
 					to fit the S_POSITION struct
 */
void get_position( S_POSITION *pos ) {
	char input[255];
	char inputWhiteL[5];
	char inputBlackL[5];
	char inputCoin0[3];
	char inputCoin1[3];
	char inputSide;
	
	if ( fgets( input, sizeof input, stdin ) ) {
		input[ strcspn(input, "\n") ] = '\0';
	
		// separate input into the five different components
		strncpy(inputWhiteL, input, 4);
		inputWhiteL[4] = '\0';
		
		strncpy(inputBlackL, input+5, 4);
		inputBlackL[4] = '\0';
		
		strncpy(inputCoin0, input+10, 2);
		inputCoin0[2] = '\0';
		
		strncpy(inputCoin1, input+13, 2);
		inputCoin1[2] = '\0';
		
		inputSide = input[16];
	}
	else {
		printf( "ERROR: reading stdin\n" );
		ASSERT( FALSE );
	}
	
	// copy full input string onto posString
	strncpy( pos->posString, input, sizeof(pos->posString) );
	pos->posString[POS_STRING_LENGTH-1] = '\0';
	
	// parse Ls and assign related integer
	pos->whiteL = parse_integerOfL( inputWhiteL );
	pos->blackL = parse_integerOfL( inputBlackL );
	
	// parse coins and assign related integer
	pos->coins[0] = parse_integerOfCoin( inputCoin0 );
	pos->coins[1] = parse_integerOfCoin( inputCoin1 );
	
	// determine side from input string
	if ( inputSide == '0' ) {
		pos->side = 0;
	}
	else if ( inputSide == '1' ) {
		pos->side = 1;
	}
	else {
		printf( "ERROR: parsing side\n" );
		ASSERT( FALSE );
	}
	
	update_board( pos );
}
























