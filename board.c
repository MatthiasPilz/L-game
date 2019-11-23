#include "defs.h"
#include<stdio.h>
#include<stdlib.h>

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
	printf("side:%c\n",SideChar[pos->side]);
}

// #############################################################################

void update_board( S_POSITION *pos ) {

}



























