#include "defs.h"
#include<stdio.h>
#include<stdlib.h>


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
		ASSERT( pos->whiteL < NO_MOVE && pos->whiteL >= 0 );
	cornerWhiteL = LPosFields[pos->whiteL];
	pos->board[cornerWhiteL] = wL;
	
		// long side
	direction = LongSideDirection[pos->whiteL];
	pos->board[cornerWhiteL + direction] = wL;
	pos->board[cornerWhiteL + 2*direction] = wL;

		// short side
	direction = ShortSideDirection[pos->whiteL];
	pos->board[cornerWhiteL + direction] = wL;
    
    
    // BLACK PIECE
    	// corner piece
		ASSERT( pos->blackL < NO_MOVE && pos->blackL >= 0 );
	cornerBlackL = LPosFields[pos->blackL];
	pos->board[cornerBlackL] = bL;

		// long side
	direction = LongSideDirection[pos->blackL];
	pos->board[cornerBlackL + direction] = bL;
	pos->board[cornerBlackL + 2*direction] = bL;
	
		// short side
	direction = ShortSideDirection[pos->blackL];
	pos->board[cornerBlackL + direction] = bL;
    
    
    // COINS
		ASSERT( pos->board[pos->coins[0]] != OFFBOARD );
	pos->board[pos->coins[0]] = cN;
		ASSERT( pos->board[pos->coins[1]] != OFFBOARD );
	pos->board[pos->coins[1]] = cN;
}

// #############################################################################


























