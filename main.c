#include "defs.h"

int main( int argc, char *argv[] ) {
	
	S_POSITION pos;
	init_startingPosition( &pos );
	
	while( TRUE ) {
		reset_board( &pos );
		delay(1);
		pos.whiteL = read_LMove();
		update_board( &pos );
		print_board( &pos );
	};
	
	return 0;
}
