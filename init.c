#include "defs.h"
#include<string.h>

/*
 *	input: 			S_POSITION struct *pos
 *	output:			none (updates pos)
 *	description: 	Initialise the game position and board according to the 
 *					standard starting position.
 */
void init_startingPosition( S_POSITION *pos ) {
	reset_board( pos );
	
	pos->side = WHITE;
	pos->whiteL = B1ur;
	pos->blackL = C4dl;
	pos->coins[0] = A4;
	pos->coins[1] = D1;	
	strcpy( pos->posString, START_POS );

	update_board( pos );	
}
