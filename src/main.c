#include "header.h"

int main(int argc, char *argv[]) {
	int **s_board;
	int n;
	int i;
	int ch;
	tile blank;

	if(argc != 2) {
		printf("%s <press size of board>\n", argv[0]);
		exit(1);
	}
	n = atoi(argv[1]);

	s_board = (int **)calloc(n, sizeof(int *));
	for(i = 0;i < n; ++i)
		s_board[i] = (int *)calloc(n, sizeof(int));
	init_board(s_board, n, &blank);
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	shuffle_board(s_board, n);
	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {
			case KEY_LEFT:
				move_blank(RIGHT, s_board, n, &blank);
				break;
			case KEY_RIGHT:
				move_blank(LEFT, s_board, n, &blank);
				break;
			case KEY_UP:
				move_blank(DOWN, s_board, n, &blank);
				break;
			case KEY_DOWN:
				move_blank(UP, s_board, n, &blank);
				break;
		}
		shuffle_board(s_board, n);

		
		if(check_win(s_board, n, &blank) == TRUE) {
			mvprintw(24, 0, "You Win !!!\n");
			refresh();
			break;
		}
		
	}

	endwin();
	return 0;	
}
