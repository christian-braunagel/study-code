/*
 * File: chessFields.c
 * Description: Chessboard visualization program
 */

#include <stdio.h>

int main(void)
{
    const int BOARD_SIZE = 8;
    char rows[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for (int i = BOARD_SIZE; i > 0; i--)
    {

        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%5c%d", rows[j], i);
        }
        printf("\n");
    }

    return 0;
}
