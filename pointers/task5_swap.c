#include <stdio.h>

/* Matches the required signature void swap(void *x, void *y); The
 * elements pointed to are treated as int, since void* carries no
 * size information for a fully generic swap. */
void swap(void *x, void *y) {
    int *ix = x;
    int *iy = y;
    int tmp = *ix;
    *ix = *iy;
    *iy = tmp;
}

int main(void) {
    int a = 5, b = 9;

    printf("before: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("after:  a = %d, b = %d\n", a, b);

    return 0;
}
