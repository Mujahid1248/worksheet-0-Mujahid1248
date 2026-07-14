CC = clang
CFLAGS = -Wall

POINTER_SRCS = $(wildcard pointers/task*.c)
POINTER_BINS = $(patsubst pointers/%.c,pointers/%,$(POINTER_SRCS))

.PHONY: all clean

all: $(POINTER_BINS) tictactoe/tictactoe

pointers/%: pointers/%.c
	$(CC) $(CFLAGS) -o $@ $<

tictactoe/tictactoe: tictactoe/main.c tictactoe/board.c tictactoe/board.h
	$(CC) $(CFLAGS) -o tictactoe/tictactoe tictactoe/main.c tictactoe/board.c

clean:
	rm -f $(POINTER_BINS) tictactoe/tictactoe
