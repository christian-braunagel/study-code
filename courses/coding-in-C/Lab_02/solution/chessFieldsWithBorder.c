/*
 * File: chessFieldsWithBorder.c
 * Description: Chessboard visualization program
 */

#include <stdio.h>

int main(void)
{
    const int BOARD_SIZE = 8;
    char rows[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // naming of files on the top of the border
    printf(" ");
    for (int file = 0; file <= 7; file++)
    {
        printf("   %c", rows[file]);
    }
    printf("\n");

    for (int i = BOARD_SIZE; i > 0; i--)
    {
        // Top Border and border between rows
        printf("  +");
        for (int k = 0; k <= 7; k++)
        {
            printf("---+");
        }
        printf("\n");

        // rank numbering left
        printf("%d ", i);
        for (int j = 1; j <= BOARD_SIZE; j++)
        {
            // coloring of the fields
            if (((j + i) % 2) > 0)
            {
                printf("|###");
            }
            else
            {
                printf("|   ");
            }
        }
        // rank numbering right
        printf("| %d\n", i);
    }

    // Border on bottom
    printf("  +");
    for (int k = 0; k <= 7; k++)
    {
        printf("---+");
    }
    printf("\n");

    // naming of files on the bottom of the border
    printf(" ");
    for (int file = 0; file <= 7; file++)
    {
        printf("   %c", rows[file]);
    }
    printf("\n");

    return 0;
}
