#include "defs.h"

char PceChar[] = " XO*";
char SideChar[] = "XO-";
char RankChar[] = "1234";
char FileChar[] = "ABCD";

int LPosFields[] = {A2, A1, B2, B1, C2, C1, 	// 	|_
					B2, B1, C2, C1, D2, D1,		// 		_|
					C3, C2, C1, D3, D2, D1, 	// __|
					C4, C3, C2, D4, D3, D2, 	// 		¯¯|
					B4, B3, C4, C3, D4, D3, 	// 	¯|
					A4, A3, B4, B3, C4, C3, 	// 		|¯
					A4, A3, A2, B4, B3, B2, 	// |¯¯
					A3, A2, A1, B3, B2, B1, 	// 		|__ 
					OFFBOARD};	
	
int LongSideDirection[] = {
				up, 	up, 	up, 	up, 	up, 	up, 	// 	|_
				up, 	up, 	up, 	up, 	up, 	up,		// 		_|
				left,	left, 	left,	left,	left, 	left, 	// __|
				left,	left, 	left,	left,	left, 	left, 	// 		¯¯|
				down, 	down, 	down, 	down, 	down, 	down,	// 	¯|
				down, 	down, 	down, 	down, 	down, 	down,	// 		|¯
				right, 	right, 	right, 	right, 	right, 	right,	// |¯¯
				right, 	right, 	right, 	right, 	right, 	right,	// 		|__
				NO_DIR};
				
int ShortSideDirection[] = {	
				right, 	right, 	right, 	right, 	right, 	right, 	// 	|_
				left,	left, 	left,	left,	left, 	left,	// 		_|
				up, 	up, 	up, 	up, 	up, 	up, 	// __|
				down, 	down, 	down, 	down, 	down, 	down, 	// 		¯¯|
				left,	left, 	left,	left,	left, 	left, 	// 	¯|
				right, 	right, 	right, 	right, 	right, 	right, 	// 		|¯
				down, 	down, 	down, 	down, 	down, 	down, 	// |¯¯
				up, 	up, 	up, 	up, 	up, 	up,		// 		|__
				NO_DIR};				
				
				
				
