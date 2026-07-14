#include <stdio.h>
#include "board.h"

int main(void) {
    char board[BOARD_SIZE * BOARD_SIZE];
    board_init(board);

    char players[2] = {'X', 'O'};
    int turn = 0;

    printf("Tic-Tac-Toe. Enter row and column (0-2) when prompted.\n\n");

    while (1) {
        board_print(board);

        char player = players[turn % 2];
        int row, col;

        printf("Player %c, enter row and col: ", player);
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input, exiting.\n");
            break;
        }

        if (!board_place(board, row, col, player)) {
            printf("That cell is invalid or already taken, try again.\n");
            continue;
        }

        char winner = board_winner(board);
        if (winner != ' ') {
            board_print(board);
            printf("Player %c wins!\n", winner);
            break;
        }

        if (board_full(board)) {
            board_print(board);
            printf("It's a draw!\n");
            break;
        }

        turn++;
    }

    return 0;
}
