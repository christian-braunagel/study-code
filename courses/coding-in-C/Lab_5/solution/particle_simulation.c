/*
 * File: particle_simulation.c
 * Description: Program to simulate the horizontal movement and collision of particles
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int FIELD_SIZE = 10;
    int field[10] = {0};
    int temp[10] = {0};
    int *p_field = field;
    int *p_temp = temp;

    srand(time(NULL));

    *(p_field + 2) = 1;
    *(p_field + 4) = 1;
    *(p_field + 6) = 1;

    int steps = 10;

    for (int t = 0; t < steps; t++)
    {
        // Print current field
        printf("Time %d: ", t);
        for (int i = 0; i < FIELD_SIZE; i++)
            printf("%d ", *(p_field + i));
        printf("\n");

        // Clear temp
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            *(p_temp + i) = 0;
        }

        // Move particles
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            if (*(p_field + i) == 1)
            {
                int direction = (rand() % 2) ? 1 : -1;
                int new_pos = i + direction;

                if (new_pos >= 0 && new_pos < FIELD_SIZE)
                    *(p_temp + new_pos) += 1;
                else
                    *(p_temp + i) += 1;
            }
        }

        // Handle collisions: remove overlapping particles
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            if (*(p_temp + i) > 1)
            {
                printf("Collision on index %d\n", i);
                *(p_temp + i) = 0;
            }
        }

        // Copy back to field
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            *(p_field + i) = *(p_temp + i);
        }
    }

    return 0;
}
