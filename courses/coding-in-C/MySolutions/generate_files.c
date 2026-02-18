/*
 * ============================================================================
 * File        : generate_files.c
 * Description : Generates sensor1.txt and sensor2.txt measurement files
 *               with deterministic probability signals.
 *
 * Author      : Lukas Meißner
 * Created     : 2026-02-18
 * ============================================================================
 */

#include <stdio.h>
#include <stdint.h>

#define NUM_SAMPLES     (3000U)
#define TIME_STEP       (0.02f)
#define MAX_TIME        (60.0f)

/* Detection intervals for Sensor 1 */
#define S1_INT1_START   (10.0f)
#define S1_INT1_END     (20.0f)
#define S1_INT2_START   (30.0f)
#define S1_INT2_END     (40.0f)
#define S1_INT3_START   (45.0f)
#define S1_INT3_END     (55.0f)

/* Detection intervals for Sensor 2 */
#define S2_INT1_START   (15.0f)
#define S2_INT1_END     (25.0f)
#define S2_INT2_START   (30.0f)
#define S2_INT2_END     (40.0f)
#define S2_INT3_START   (50.0f)
#define S2_INT3_END     (59.98f)

/* Probability levels */
#define BACKGROUND_PROB (0.2)
#define DETECTION_PROB  (0.9)

/* ============================ Main ===================================== */

int main(void)
{
    FILE *file1 = fopen("sensor1.txt", "w");
    FILE *file2 = fopen("sensor2.txt", "w");

    if ((file1 == NULL) || (file2 == NULL))
    {
        printf("Error creating output files.\n");
        return 1;
    }

    for (uint32_t i = 0U; i < NUM_SAMPLES; ++i)
    {
        float time = (float)i * TIME_STEP;

        double prob1 = BACKGROUND_PROB;
        double prob2 = BACKGROUND_PROB;

        /* Sensor 1 intervals */
        if ((time >= S1_INT1_START && time <= S1_INT1_END) ||
            (time >= S1_INT2_START && time <= S1_INT2_END) ||
            (time >= S1_INT3_START && time <= S1_INT3_END))
        {
            prob1 = DETECTION_PROB;
        }

        /* Sensor 2 intervals */
        if ((time >= S2_INT1_START && time <= S2_INT1_END) ||
            (time >= S2_INT2_START && time <= S2_INT2_END) ||
            (time >= S2_INT3_START && time <= S2_INT3_END))
        {
            prob2 = DETECTION_PROB;
        }

        fprintf(file1, "%.2f %.2f\n", time, prob1);
        fprintf(file2, "%.2f %.2f\n", time, prob2);
    }

    fclose(file1);
    fclose(file2);

    printf("Files sensor1.txt and sensor2.txt generated successfully.\n");

    return 0;
}
