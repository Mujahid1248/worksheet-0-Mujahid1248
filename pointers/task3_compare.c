#include <stdio.h>

int elements_equal(const int *a, const int *b, int length) {
    if (a == NULL || b == NULL) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    int c[5] = {1, 2, 3, 4, 6};

    printf("a vs b (should match): %d\n", elements_equal(a, b, 5));
    printf("a vs c (should not match): %d\n", elements_equal(a, c, 5));
    printf("a vs NULL (should not match): %d\n", elements_equal(a, NULL, 5));

    return 0;
}
