#include <stdio.h>

void print_array(int *arr, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%4d ", *(arr + row * width + col));
        }
        printf("\n");
    }
}

int main(void) {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_array(&arr[0][0], 3, 2);

    return 0;
}
