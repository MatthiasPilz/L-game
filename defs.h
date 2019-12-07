#ifndef DEFS_H
	#define DEFS_H

	#include<stdlib.h>
	#include<stdio.h>

	// define ASSERT for debugging
	// toggle #define DEBUG to turn it on/off
	//#define DEBUG
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
	
	// MACRO VARIABLES
	#define BOARD_SQ_NUM 80
	#define START_POS "B1ur/C4dl/A4/D1/w"
	#define POS_STRING_LENGTH 18

	// fake boolean :)
	enum { FALSE, TRUE };
	
	// possible field states on the playing area of the board
	enum { EMPTY, wL, bL, cN };
	
	// integer assignment for fields of the playing area
	enum {
  		A1 = 23, B1, C1, D1,
  		A2 = 33, B2, C2, D2, 
  		A3 = 43, B3, C3, D3, 
  		A4 = 53, B4, C4, D4, OFFBOARD
		};
	
	// useful definitions for printing	
	enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_NONE };
	enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_NONE };
	
	// possible sides
	enum { WHITE, BLACK, BOTH };
	
	// possible positions for one L
	enum LPOSITION {
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
		
	// possible direction of the arms of the L and how they translate on the 
	// 80-field board representation
	enum { up=10, down=-10, left=-1, right=1, NO_DIR=0 };
	
	// summary of one position, including location of the pieces, whose turn it
	// is, and 80-field board representation
	typedef struct {
		int board[BOARD_SQ_NUM];
		int side;
		int whiteL;
		int blackL;
		int coins[2];
		char posString[POS_STRING_LENGTH];   // 
	} S_POSITION;
	
	typedef struct { 
		char *key; 
		int val; 
	} S_DICT;
	
	typedef struct {
		S_DICT lPos;
	} S_LMOVE;
	
	typedef struct { 
		S_DICT from;
		S_DICT to;
	} S_COINMOVE;
	
	typedef struct { 
		S_LMOVE lMove;
		S_COINMOVE coinMove;
	} S_MOVE;
	
	// MACROS
		// translate file and rank to square on the playing area
	#define FR2SQ(f,r) ( (23 + (f) ) + ( (r) * 10 ) )
	
	// GLOBALS
	extern char SideChar[];
	extern char PceChar[];
	extern char FileChar[];
	extern char RankChar[];
	extern int LPosFields[];
	extern int LongSideDirection[];
	extern int ShortSideDirection[];
	
	static S_DICT LMoveLookupTable[] = {
			{"A2ur", A2ur}, {"A1ur", A1ur}, {"B2ur", B2ur}, 	// 	|_
			{"B1ur", B1ur}, {"C2ur", C2ur}, {"C1ur", C1ur},
			{"B2ul", B2ul}, {"B1ul", B1ul}, {"C2ul", C2ul}, 	// 		_|
			{"C1ul", C1ul}, {"D2ul", D2ul}, {"D1ul", D1ul},
			{"C3lu", C3lu}, {"C2lu", C2lu}, {"C1lu", C1lu}, 	// __| 
			{"D3lu", D3lu}, {"D2lu", D2lu}, {"D1lu", D1lu},
			{"C4ld", C4ld}, {"C3ld", C3ld}, {"C2ld", C2ld}, 	// 		¯¯|
			{"D4ld", D4ld}, {"D3ld", D3ld}, {"D2ld", D2ld}, 
			{"B4dl", B4dl}, {"B3dl", B3dl}, {"C4dl", C4dl}, 	// 	¯|
			{"C3dl", C3dl}, {"D4dl", D4dl}, {"D3dl", D3dl}, 
			{"A4dr", A4dr}, {"A3dr", A3dr}, {"B4dr", B4dr}, 	// 		|¯
			{"B3dr", B3dr}, {"C4dr", C4dr}, {"C3dr", C3dr}, 
			{"A4rd", A4rd}, {"A3rd", A3rd}, {"A2rd", A2rd}, 	// |¯¯
			{"B4rd", B4rd}, {"B3rd", B3rd}, {"B2rd", B2rd}, 
			{"A3ru", A3ru}, {"A2ru", A2ru}, {"A1ru", A1ru}, 	// 		|__
			{"B3ru", B3ru}, {"B2ru", B2ru}, {"B1ru", B1ru}};	
			
	static S_DICT coinMoveLookupTable[] = {
			{"A1", A1}, {"A2", A2}, {"A3", A3}, {"A4", A4},
			{"B1", B1}, {"B2", B2}, {"B3", B3}, {"B4", B4},
			{"C1", C1}, {"C2", C2}, {"C3", C3}, {"C4", C4},
			{"D1", D1}, {"D2", D2}, {"D3", D3}, {"D4", D4},
			{"--", OFFBOARD}};
	
	// FUNCTIONS	
		// board.c
	extern void print_board( const S_POSITION *pos );
	extern void reset_board( S_POSITION *pos );
	extern void update_board( S_POSITION *pos );
	extern void get_position( S_POSITION *pos );
		
		// init.c
	extern void init_startingPosition( S_POSITION *pos );
	
		// move.c
	extern S_MOVE get_move( void );
	
		// util.c
	extern void delay( int number_of_seconds );
	
#endif
