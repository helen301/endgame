#pragma once

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define STARTX 9
#define STARTY 3
#define WIDTH  6
#define HEIGHT 4

#define BLANK 0

typedef struct _tile {
	int x;
	int y;
}              tile;

void init_board(int **board, int n, tile *blank);
void board(WINDOW *win, int starty, int startx, int lines, int cols, int tile_width, int tile_height);
void shuffle_board(int **board, int n);
void move_blank(int direction, int **s_board, int n, tile *blank);
int check_win(int **s_board, int n, tile *blank);

enum { LEFT, RIGHT, UP, DOWN };
