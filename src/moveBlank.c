#include "header.h"

void move_blank(int direction, int **s_board, int n, tile *blank) {
    int temp; 
	switch(direction) {
        case LEFT:
        	if(blank->x != 0) {
                --blank->x;
				temp = s_board[blank->x][blank->y];
				s_board[blank->x + 1][blank->y] = temp;
				s_board[blank->x][blank->y] = BLANK;
			}
			break;
		case RIGHT:
	    	if(blank->x != n - 1) {
                ++blank->x;
				temp = s_board[blank->x][blank->y];
				s_board[blank->x - 1][blank->y] = temp;
				s_board[blank->x][blank->y] = BLANK;
			}
			break;
		case UP:
			if(blank->y != 0) {
                --blank->y;
				temp = s_board[blank->x][blank->y];
				s_board[blank->x][blank->y + 1] = temp;
				s_board[blank->x][blank->y] = BLANK;
			}
			break;
		case DOWN:
			if(blank->y != n - 1) {
                ++blank->y;
				temp = s_board[blank->x][blank->y];
				s_board[blank->x][blank->y - 1] = temp;
				s_board[blank->x][blank->y] = BLANK;
			}
			break;			
	}
}
