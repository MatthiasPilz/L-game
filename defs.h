#ifndef DEFS_H
#define DEFS_H

	#include "stdlib.h"
	#include "stdio.h"

	// define ASSERT for debugging
	// toggle #define DEBUG to turn it on/off
	#define DEBUG
	#ifndef DEBUG
		#define ASSERT(n)
	#else
		#define ASSERT(n) \
		if(!(n)) { \
			printf("%s - Failed",#n); \
			printf("On %s ",__DATE__); \
			printf("At %s ",__TIME__); \
			printf("In File %s ",__FILE__); \
			printf("At Line %d\n",__LINE__); \
			exit(1);}
	#endif
	
	#define BOARD_SQ_NUM 80

	enum { FALSE, TRUE };
	enum {
  		A1 = 23, B1, C1, D1,
  		A2 = 33, B2, C2, D2, 
  		A3 = 43, B3, C3, D3, 
  		A4 = 53, B4, C4, D4, NO_SQ, OFFBOARD
		};
	enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_NONE };
	enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_NONE };
	
	typedef struct {
		int pieces[BOARD_SQ_NUM];
		int side;
	} S_BOARD;
	
	// MACROS
	#define FR2SQ(f,r) ( (23 + (f) ) + ( (r) * 10 ) )

#endif
