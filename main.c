#include "defs.h"

int main( int argc, char *argv[] ) {
	
	S_POSITION pos;
	init_startingPosition( &pos );
	
	while ( TRUE ) {		
		print_board( &pos );
		reset_board( &pos );	
		get_position( &pos );
	}
	
	return 0;
}
