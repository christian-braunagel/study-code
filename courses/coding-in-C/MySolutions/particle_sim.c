/*
 * ============================================================================
 * File        : particle_sim.c
 * Description : 1D particle system simulation using pointers.
 *               Particles move randomly left or right.
 *               Collisions remove particles.
 *
 * Author      : Lukas Meißner
 * Created     : 2026-02-16
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/* ============================ Macros ===================================== */

#define FIELD_SIZE          (10U)
#define PARTICLE_PRESENT    (1U)
#define CELL_EMPTY          (0U)
#define TIME_STEPS          (10U)

/* ============================ Main ======================================= */

int main(void)
{
    uint8_t field[FIELD_SIZE] = {0U};
    uint8_t temp_field[FIELD_SIZE] = {0U};

    uint8_t *p_field      = &field[0];
    uint8_t *p_temp_field = &temp_field[0];

    uint32_t step;
    uint32_t i;

    /* Initialize random seed */
    srand((unsigned int)time(NULL));

    /* Place three particles (even distance to allow collisions) */
    *(p_field + 2U) = PARTICLE_PRESENT;
    *(p_field + 4U) = PARTICLE_PRESENT;
    *(p_field + 6U) = PARTICLE_PRESENT;

    /* ====================== Simulation Loop ============================== */

    for (step = 0U; step < TIME_STEPS; ++step)
    {
        printf("Time %u: ", step);

        /* Print current field */
        for (i = 0U; i < FIELD_SIZE; ++i)
        {
            printf("%u ", *(p_field + i));
        }
        printf("\n");

        /* Reset temporary field */
        for (i = 0U; i < FIELD_SIZE; ++i)
        {
            *(p_temp_field + i) = CELL_EMPTY;
        }

        /* Move particles */
        for (i = 0U; i < FIELD_SIZE; ++i)
        {
            if (*(p_field + i) == PARTICLE_PRESENT)
            {
                int32_t direction = (rand() % 2 == 0) ? -1 : 1;
                int32_t new_position = (int32_t)i + direction;

                /* Prevent out-of-bounds movement */
                if (new_position < 0)
                {
                    new_position = 0;
                }
                else if (new_position >= (int32_t)FIELD_SIZE)
                {
                    new_position = (int32_t)FIELD_SIZE - 1;
                }

                /* Collision handling */
                if (*(p_temp_field + new_position) == PARTICLE_PRESENT)
                {
                    /* Collision: remove particle */
                    *(p_temp_field + new_position) = CELL_EMPTY;
                    printf("Collision on index %ld\n", (long)new_position);
                }
                else
                {
                    *(p_temp_field + new_position) = PARTICLE_PRESENT;
                }
            }
        }

        /* Copy temp field back to main field */
        for (i = 0U; i < FIELD_SIZE; ++i)
        {
            *(p_field + i) = *(p_temp_field + i);
        }
    }

    return 0;
}
