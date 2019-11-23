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
	#define START_POS "B1ur/C4dl/A4/D1/w"
	#define POS_STRING_LENGTH 17

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
	enum { up, down, left, right, NO_DIR };
	
	enum {
		A2ur, A1ur, B2ur, B1ur, C2ur, C1ur, 	// 	|_
		B2ul, B1ul, C2ul, C1ul, D2ul, D1ul,		// 		_|
		C3lu, C2lu, C1lu, D3lu, D2lu, D1lu, 	// __|
		C4ld, C3ld, C2ld, D4ld, D3ld, D2ld, 	// 		¯¯|
		B4dl, B3dl, C4dl, C3dl, D4dl, D3dl, 	// 	¯|
		A4dr, A3dr, B4dr, B3dr, C4dr, C3dr, 	// 		|¯
		A4rd, A3rd, A2rd, B4rd, B3rd, B2rd, 	// |¯¯
		A3ru, A2ru, A1ru, B3ru, B2ru, B1ru, 	// 		|__
		NO_MOVE
		};
	
	typedef struct {
		int board[BOARD_SQ_NUM];
		int side;
		int whiteL;
		int blackL;
		int coins[2];
		char posString[POS_STRING_LENGTH];   // 
	} S_POSITION;
	
	// MACROS
	#define FR2SQ(f,r) ( (23 + (f) ) + ( (r) * 10 ) )
	
	
	// GLOBALS
	extern char SideChar[];
	extern char PceChar[];
	extern char FileChar[];
	extern char RankChar[];
	extern int LPosFields[];
	extern int LongSideDirection[];
	extern int ShortSideDirection[];
	
	// FUNCTIONS
	
	// board.c
	extern void print_board( const S_POSITION *pos );
	extern void reset_board( S_POSITION *pos );
	extern void update_board( S_POSITION *pos );
	
	// init.c
	extern void init_position( S_POSITION *pos );
	

#endif
