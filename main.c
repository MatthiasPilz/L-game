#include "defs.h"

int main( int argc, char *argv[] ) {
	
	S_POSITION pos;
	init_position( &pos );
	print_board( &pos );
	
	return 0;
}
