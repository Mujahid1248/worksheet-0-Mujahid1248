# UFCFWK-15-2 Operating Systems — Worksheet 0: An echo of C


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

<img width="817" height="68" alt="image" src="https://github.com/user-attachments/assets/9858d239-1068-4cd6-99fb-77955fc4d805" />

```

**Task 2** — array walked via pointer arithmetic (`*(p + i)`), printing each element and its address:
```
<img width="826" height="97" alt="image" src="https://github.com/user-attachments/assets/99fdc42f-2db4-4cde-9592-7b49f228f488" />

```

**Task 3** — `elements_equal` returns `0` immediately if either pointer is `NULL`, otherwise
compares element-by-element for `length` elements:
```
<img width="737" height="95" alt="image" src="https://github.com/user-attachments/assets/5fc3e3ea-c84f-433f-8b43-26dbc004eced" />

```

**Task 4** — reads `foo.txt` (10, 20, 30, 40, 54) with `fscanf` in a loop and sums:
```
<img width="788" height="40" alt="image" src="https://github.com/user-attachments/assets/efcd81c5-aef5-4c86-9758-cf28b1473f1c" />
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

<img width="712" height="67" alt="image" src="https://github.com/user-attachments/assets/944e867a-054e-4532-9453-8ed917773edb" />

```

**Task 6** — `print_array` walks a flattened 2D array using `arr[row*width + col]`:
```
<img width="795" height="77" alt="image" src="https://github.com/user-attachments/assets/8bc49bce-6617-4218-b4ff-d47f77b20aa6" />

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
<img width="487" height="275" alt="image" src="https://github.com/user-attachments/assets/dc92a6a9-3dcd-4d38-8f0d-2da7c5321d84" />

```

## Building

```
make      
```
