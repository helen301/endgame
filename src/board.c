#include "header.h"

void board(WINDOW *win, int starty, int startx, int lines, int cols, int tile_width, int tile_height) {
    int endy;
	int endx;
	int i;
	int j;
	
	endy = starty + lines * tile_height;
	endx = startx + cols  * tile_width;
	for(j = starty; j <= endy; j += tile_height)
		for(i = startx; i <= endx; ++i)
			mvwaddch(win, j, i, ACS_HLINE);
	for(i = startx; i <= endx; i += tile_width)
		for(j = starty; j <= endy; ++j)
			mvwaddch(win, j, i, ACS_VLINE);
	mvwaddch(win, starty, startx, ACS_ULCORNER);
	mvwaddch(win, endy, startx, ACS_LLCORNER);
	mvwaddch(win, starty, endx, ACS_URCORNER);
	mvwaddch(win, 	endy, endx, ACS_LRCORNER);
	for(j = starty + tile_height; j <= endy - tile_height; j += tile_height) {
        mvwaddch(win, j, startx, ACS_LTEE);
		mvwaddch(win, j, endx, ACS_RTEE);	
		for(i = startx + tile_width; i <= endx - tile_width; i += tile_width)
			mvwaddch(win, j, i, ACS_PLUS);
	}
	for(i = startx + tile_width; i <= endx - tile_width; i += tile_width) {
        mvwaddch(win, starty, i, ACS_TTEE);
		mvwaddch(win, endy, i, ACS_BTEE);
	}
	wrefresh(win);
}
