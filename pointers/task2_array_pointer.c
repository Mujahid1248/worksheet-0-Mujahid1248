#include <stdio.h>

int main(void) {
    int arr[3] = {10, 30, 2000};
    int *p = arr;

    for (int i = 0; i < 3; i++) {
        printf("element = %d, address = %p\n", *(p + i), (void *)(p + i));
    }

    return 0;
}
