#include <stdio.h>
#include "board.h"

void board_init(char *board) {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        *(board + i) = ' ';
    }
}

void board_print(const char *board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            putchar(*(board + row * BOARD_SIZE + col));
            if (col < BOARD_SIZE - 1) {
                putchar('|');
            }
        }
        putchar('\n');
        if (row < BOARD_SIZE - 1) {
            for (int i = 0; i < BOARD_SIZE * 2 - 1; i++) {
                putchar('-');
            }
            putchar('\n');
        }
    }
}

int board_place(char *board, int row, int col, char player) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }

    char *cell = board + row * BOARD_SIZE + col;
    if (*cell != ' ') {
        return 0;
    }

    *cell = player;
    return 1;
}

static int line_wins(const char *a, const char *b, const char *c) {
    return *a != ' ' && *a == *b && *b == *c;
}

char board_winner(const char *board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        const char *r = board + row * BOARD_SIZE;
        if (line_wins(r, r + 1, r + 2)) {
            return *r;
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++) {
        const char *c0 = board + col;
        const char *c1 = board + BOARD_SIZE + col;
        const char *c2 = board + 2 * BOARD_SIZE + col;
        if (line_wins(c0, c1, c2)) {
            return *c0;
        }
    }

    if (line_wins(board, board + 4, board + 8)) {
        return *board;
    }
    if (line_wins(board + 2, board + 4, board + 6)) {
        return *(board + 2);
    }

    return ' ';
}

int board_full(const char *board) {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (*(board + i) == ' ') {
            return 0;
        }
    }
    return 1;
}
