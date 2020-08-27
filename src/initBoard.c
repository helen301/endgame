#include "header.h"

void init_board(int **s_board, int n, tile *blank) {
    int i;
	int j;
	int k;
	int *temp_board;

	temp_board = (int *)calloc(n * n, sizeof(int));
	srand(time(NULL));
	for(i = 0;i < n * n; ++i) {    
        repeat :
		k = rand() % (n * n);
		for(j = 0;j <= i - 1; ++j)
			if (k == temp_board[j])
				goto repeat;
			else
				temp_board[i] = k;
	}
	k = 0;
	for (i = 0;i < n;++i)
		for(j = 0;j < n; ++j,++k) {
            if(temp_board[k] == 0) {
                blank->x = i;
				blank->y = j;
			}
			s_board[i][j] = temp_board[k];
		}
	free(temp_board);
}
