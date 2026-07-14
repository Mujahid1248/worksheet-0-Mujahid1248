# UFCFWK-15-2 Operating Systems — Worksheet 0: An echo of C

Individual submission. Worked with: **_(fill in — "worked alone" or list collaborators here, as
required by the assignment brief)_**.

All code was written, compiled (`clang`), and run on `csctcloud.uwe.ac.uk`.

> Note: this README contains the actual terminal output captured while testing each program on
> the remote server, as evidence the code works. Replace/add real screenshots (VS Code + terminal)
> before submission, per the assignment's screenshot requirement.

---

## Pointer tasks (`pointers/`)

| File | Task |
|---|---|
| `task1_increment.c` | Pointer to a local variable, increment through the pointer |
| `task2_array_pointer.c` | Array of 3 elements, walked with a pointer |
| `task3_compare.c` | `elements_equal(a, b, length)` — null-safe pointer comparison |
| `task4_sum_file.c` | Reads `foo.txt`, sums the numbers |
| `task5_swap.c` | `void swap(void *x, void *y)` |
| `task6_print_array.c` | `void print_array(int *arr, int width, int height)` for a 2D array |

**Task 1** — pointer to `n`, increment through the pointer:

```c
int n = 10;
int *ptr_to_n = &n;
*ptr_to_n = *ptr_to_n + 1;
```

Output:
```
n = 11
*ptr_to_n = 11
```

**Task 2** — array walked via pointer arithmetic (`*(p + i)`), printing each element and its address:
```
element = 10, address = 0x7ffd09ca7c70
element = 30, address = 0x7ffd09ca7c74
element = 2000, address = 0x7ffd09ca7c78
```
Note the addresses are 4 bytes apart — the size of an `int`.

**Task 3** — `elements_equal` returns `0` immediately if either pointer is `NULL`, otherwise
compares element-by-element for `length` elements:
```
a vs b (should match): 1
a vs c (should not match): 0
a vs NULL (should not match): 0
```

**Task 4** — reads `foo.txt` (10, 20, 30, 40, 54) with `fscanf` in a loop and sums:
```
sum = 154
```

**Task 5** — `swap` takes `void *x, void *y` (the exact signature given in the worksheet). Since a
`void*` carries no size information, the implementation treats the pointees as `int`:
```c
void swap(void *x, void *y) {
    int *ix = x, *iy = y;
    int tmp = *ix;
    *ix = *iy;
    *iy = tmp;
}
```
```
before: a = 5, b = 9
after:  a = 9, b = 5
```

**Task 6** — `print_array` walks a flattened 2D array using `arr[row*width + col]`:
```
   1    2    3
   4    5    6
```

## TicTacToe (`tictactoe/`)

Split across multiple source files:
- `board.h` / `board.c` — board state, printing, placing a move (via pointer arithmetic on the
  board array), and win/draw detection.
- `main.c` — game loop, alternates `X`/`O`, reads `row col` from the user.

`board_place` is the pointer-using function required by the spec:
```c
int board_place(char *board, int row, int col, char player) {
    char *cell = board + row * BOARD_SIZE + col;
    if (*cell != ' ') return 0;
    *cell = player;
    return 1;
}
```

Sample run (moves `0 0`, `0 1`, `1 0`, `1 1`, `2 0` — X takes the left column and wins):
```
X|O|
-----
X|O|
-----
X| |
Player X wins!
```

## Building

```
make        # builds all pointer-task binaries and tictactoe/tictactoe
```
