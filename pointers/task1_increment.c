#include <stdio.h>

int main(void) {
    int n = 10;
    int *ptr_to_n = &n;

    *ptr_to_n = *ptr_to_n + 1;

    printf("n = %d\n", n);
    printf("*ptr_to_n = %d\n", *ptr_to_n);

    return 0;
}
