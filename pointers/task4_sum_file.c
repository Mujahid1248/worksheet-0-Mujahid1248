#include <stdio.h>

int main(void) {
    FILE *fp = fopen("foo.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    int value;
    int sum = 0;
    while (fscanf(fp, "%d", &value) == 1) {
        sum += value;
    }

    fclose(fp);

    printf("sum = %d\n", sum);

    return 0;
}
