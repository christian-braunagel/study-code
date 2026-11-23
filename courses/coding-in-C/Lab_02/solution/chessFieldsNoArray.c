/*
 * File: chessFieldsNoArray.c
 * Description: Chessboard visualization program alternative not using arrays
 */

#include <stdio.h>

int main(void)
{
    const int BOARD_SIZE = 8;

    for (int i = BOARD_SIZE; i > 0; i--)
    {

        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%5c%d", 'A' + j, i); // ASCII value is used which is increased per iteration
        }
        printf("\n");
    }

    return 0;
}
