#include <stdio.h>

int main(void) {
    int row, col;

    for (row = 8; row >= 1; row--) {
        for (col = 0; col < 8; col++) {
            if ((row + col) % 2 == 0) {
                printf("##");
            } else {
                printf("--");
            }
        }
        printf("\n\n");
    }

    return 0;
}
