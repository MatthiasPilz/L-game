#include "defs.h"
#include<stdio.h>
#include<stdlib.h>


int get_directionOffset( int direction ) {
	int result = 0;
	switch(direction) {
   		case up:
   			result = 10;
      		break; 
	
   		case down:
   			result = -10;
      		break; 
  
		case left:
			result = -1;
			break;
			
		case right:
			result = 1;
			break;
			
   		default :
   			printf( "ERROR parsing position\n" );
   			ASSERT( FALSE );
   	}
   	
   	return result;
}

// #############################################################################

void reset_board(S_POSITION *pos) {
	
	int index = 0;
	int rank = RANK_1;
	int file = FILE_A;

	for(index = 0; index < BOARD_SQ_NUM; ++index) {		
		pos->board[index] = OFFBOARD;
	}

	for(rank = RANK_1; rank <= RANK_4; ++rank) {
		for(file = FILE_A; file <= FILE_D; ++file) {
			pos->board[FR2SQ(file,rank)] = EMPTY;
		}
	}
}

// #############################################################################


void print_board( const S_POSITION *pos ) {
	int sq,file,rank,piece;

	printf("\nGame Board:\n\n");
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

void update_board( S_POSITION *pos ) {
	int cornerWhiteL = LPosFields[pos->whiteL];
	int direction = 0;
	
	pos->board[cornerWhiteL] = wL;

	direction = get_directionOffset( LongSideDirection[pos->whiteL] );
   	ASSERT(cornerWhiteL + direction != OFFBOARD);
   	ASSERT(cornerWhiteL + 2*direction != OFFBOARD);
    pos->board[cornerWhiteL + direction] = wL;
    pos->board[cornerWhiteL + 2*direction] = wL;

	direction = get_directionOffset( ShortSideDirection[pos->whiteL] );
   	ASSERT(cornerWhiteL + direction != OFFBOARD);
    pos->board[cornerWhiteL + direction] = wL;
    
	int cornerBlackL = LPosFields[pos->blackL];
	
	pos->board[cornerBlackL] = bL;

	direction = get_directionOffset( LongSideDirection[pos->blackL] );
   	ASSERT(cornerBlackL + direction != OFFBOARD);
   	ASSERT(cornerBlackL + 2*direction != OFFBOARD);
    pos->board[cornerBlackL + direction] = bL;
    pos->board[cornerBlackL + 2*direction] = bL;

	direction = get_directionOffset( ShortSideDirection[pos->blackL] );
   	ASSERT(cornerBlackL + direction != OFFBOARD);
    pos->board[cornerBlackL + direction] = bL;
    
    pos->board[pos->coins[0]] = cN;
    pos->board[pos->coins[1]] = cN;
}

// #############################################################################


























