#include "defs.h"

int main( int argc, char *argv[] ) {
	
	S_POSITION pos;
	reset_board( &pos );
	print_board( &pos );
	
	return 0;
}
