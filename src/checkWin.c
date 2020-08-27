#include "header.h"

int check_win(int **s_board, int n, tile *blank) {
    int i;
	int j;

	s_board[blank->x][blank->y] = n * n;
	for(i = 0;i < n; ++i)
		for(j = 0;j < n; ++j)
			if(s_board[i][j] != j * n + i + 1) {
                s_board[blank->x][blank->y] = BLANK;
				return FALSE;
			}
	
	s_board[blank->x][blank->y] = BLANK;
	return TRUE;	
}
