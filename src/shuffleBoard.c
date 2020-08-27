#include "header.h"

void shuffle_board(int **s_board, int n) {
    int i;
	int j;
	int deltax;
	int deltay;
	int startx;
	int starty;
	char quit;

	starty = (LINES - n * HEIGHT) / 2;
	startx = (COLS  - n * WIDTH) / 2;
	clear();
	board(stdscr, starty, startx, n, n, WIDTH, HEIGHT);
	deltay = HEIGHT / 2;
	deltax = WIDTH  / 2;
	for(j = 0; j < n; ++j)
		for(i = 0;i < n; ++i)
			if(s_board[i][j] != BLANK)
				mvprintw(starty + j * HEIGHT + deltay,
					 startx + i * WIDTH  + deltax,
					 "%-2d", s_board[i][j]);
	refresh();

	scanf("%c", &quit);
	if(quit == 'q') {
		exit(0);
	}
}
