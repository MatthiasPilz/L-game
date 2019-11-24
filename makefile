all:
	gcc board.c data.c init.c main.c move.c util.c -o run_main -O2
