#include "defs.h"
#include<string.h>

void init_position( S_POSITION *pos ) {

	reset_board( pos );
	pos->side = WHITE;
	pos->whiteL = B1ur;
	pos->blackL = C4dl;
	pos->coins[0] = A4;
	pos->coins[1] = D1;
	strcpy( pos->posString, START_POS );

	update_board( pos );	
}
