#include "defs.h"

int main( int argc, char *argv[] ) {
	
	S_POSITION pos;
	init_startingPosition( &pos );
	S_MOVE test;
	
	while ( TRUE ) {
		reset_board( &pos );	
		test = get_move();
		// this test doesn't actually makes sense in the game 
		// it is only useful for visualisation
		pos.whiteL = test.lMove.lPos.val;
		pos.coins[0] = test.coinMove.from.val;
		pos.coins[1] = test.coinMove.to.val;
		update_board( &pos );
		print_board( &pos );
	}
	
	return 0;
}
