/*
 * File: generate_measurement_files.c
 * Description: Program creates exemplary sensor data files.
 */

#include <stdio.h>

#define SAMPLES 3000
#define DT 0.02

/**
 * @brief Function to generate sensor data and write it into text files.
 *
 */
int generate_measurement_files(const char *p_filename1, const char *p_filename2)
{
    FILE *p_f1 = fopen(p_filename1, "w");
    FILE *p_f2 = fopen(p_filename2, "w");

    if (p_f1 == NULL)
    {
        printf("Error: Could not open file %s\n", p_filename1);
        return -1;
    }

    if (p_f2 == NULL)
    {
        printf("Error: Could not open file %s\n", p_filename2);
        return -1;
    }

    int i;
    float t;

    for (i = 0; i < SAMPLES; i++)
    {
        t = i * DT;

        /* Sensor 1: 3 detections */
        double p1 = 0.2;
        if ((t >= 10 && t <= 20) ||
            (t >= 30 && t <= 40) ||
            (t >= 45 && t <= 55))
        {
            p1 = 0.9;
        }

        /* Sensor 2: 3 detections */
        double p2 = 0.3;
        if ((t >= 15 && t <= 25) ||
            (t >= 30 && t <= 40) ||
            (t >= 50 && t <= 60))
        {
            p2 = 0.85;
        }

        fprintf(p_f1, "%.2f %.3f\n", t, p1);
        fprintf(p_f2, "%.2f %.3f\n", t, p2);
    }

    fclose(p_f1);
    fclose(p_f2);

    return 0;
}

/**
 * @brief exemplary usage of the sensor data generator
 *
 * @return int status code
 */
int main()
{
    if (generate_measurement_files("sensor1_daten.txt", "sensor2_daten.txt") < 0)
    {
        return -1;
    }
    return 0;
}