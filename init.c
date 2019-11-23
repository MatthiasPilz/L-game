#include "defs.h"

void init_board( S_POSITION *pos ) {

	reset_board( pos );
	pos->side = WHITE;
	pos->whiteL = B1ur;
	pos->blackL = C4dl;
	pos->coins[0] = A4;
	pos->coins[1] = D1;
	pos->posString = "B1ur/C4dl/A4/D1/w"

	update_board( pos );	
}
