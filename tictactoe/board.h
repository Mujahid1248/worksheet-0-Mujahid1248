#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 3

void board_init(char *board);
void board_print(const char *board);
int board_place(char *board, int row, int col, char player);
char board_winner(const char *board);
int board_full(const char *board);

#endif
