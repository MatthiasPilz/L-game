#include "defs.h"
#include<time.h> 

void delay( int number_of_seconds ) { 
    // converting time into micro_seconds 
    int micro_seconds = 1000000 * number_of_seconds; 
  
    // record start time 
    clock_t start_time = clock(); 
  
    // looping till required time is achieved
    while (clock() < start_time + micro_seconds) { }; 
} 
