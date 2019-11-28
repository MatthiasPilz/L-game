#include "defs.h"

int main( int argc, char *argv[] ) {
	
	S_POSITION pos;
	init_startingPosition( &pos );
	S_MOVE test;
	
	while ( TRUE ) {
		reset_board( &pos );	
		test = get_move();
		pos.whiteL = test.lMove;
		pos.coins[0] = test.coinMove;
		update_board( &pos );
		print_board( &pos );
	}
	
	return 0;
}
