#include "defs.h"

int main( int argc, char *argv[] ) {
	
	S_POSITION pos;
	init_startingPosition( &pos );
	
	S_MOVE test = get_move();
	printf( "lmove: %d, coin: %d\n", test.lMove, test.coinMove );
	
	return 0;
}
