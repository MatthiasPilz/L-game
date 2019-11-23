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
	#define STARTPOS "B1ur/C4dl/A4/D1/w"

	enum { FALSE, TRUE };
	
	enum { EMPTY, wL, bL, cN };
	
	enum {
  		A1 = 23, B1, C1, D1,
  		A2 = 33, B2, C2, D2, 
  		A3 = 43, B3, C3, D3, 
  		A4 = 53, B4, C4, D4, OFFBOARD
		};
		
	enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_NONE };
	enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_NONE };
	enum { WHITE, BLACK, BOTH };
	
	enum {
		A3ur, A4ur, B3ur, B4ur, C3ur, C4ur, 	// 	|_
		B3ul, B4ul, C3ul, C4ul, D3ul, D4ul,		// 		_|
		C2lu, C3lu, C4lu, D2lu, D3lu, D4lu, 	// __|
		C1ld, C2ld, C3ld, D1ld, D2ld, D3ld, 	// 		¯¯|
		B1dl, B2dl, C1dl, C2dl, D1dl, D2dl, 	// 	¯|
		A1dr, A2dr, B1dr, B2dr, C1dr, C2dr, 	// 		|¯
		A1rd, A2rd, A3rd, B1rd, B2rd, B3rd, 	// |¯¯
		A2ru, A3ru, A4ru, B2ru, B3ru, B4ru, 	// 		|__
		NO_MOVE
		};
	
	typedef struct {
		int board[BOARD_SQ_NUM];
		int side;
		int whiteL;
		int blackL;
		int coins[2];
		char posString[];   // 
	} S_POSITION;
	
	// MACROS
	#define FR2SQ(f,r) ( (23 + (f) ) + ( (r) * 10 ) )
	
	
	// GLOBALS
	extern char SideChar[];
	extern char PceChar[];
	extern char FileChar[];
	extern char RankChar[];
	
	// FUNCTIONS
	
	// board.c
	extern void print_board( const S_POSITION *pos );
	extern void reset_board( S_POSITION *pos );
	extern void update_board( S_POSITION *pos );
	
	// init.c
	extern void init_board( S_POSITION *pos );
	

#endif
