/*
 * ============================================================================
 * File        : sensor_detection.c
 * Description : Time-discrete sensor processing with threshold detection
 *               and fused overlap detection.
 *
 * Author      : Lukas Meißner
 * Created     : 2026-02-18
 * ============================================================================
 */

#include <stdio.h>
#include <stdint.h>

#define NUM_SAMPLES        (3000U)
#define SENSOR1_THRESHOLD  (0.8)
#define SENSOR2_THRESHOLD  (0.7)

/* ============================ Data Types ================================ */

typedef struct
{
    float  time;        /* Sample time in seconds */
    double probability; /* Measured probability (0..1) */
} sensor_data_t;

typedef struct
{
    int    id;                                /* Sensor ID */
    double threshold;                         /* Detection threshold */
    sensor_data_t data[NUM_SAMPLES];          /* Measurement samples */
    int    object_detection[NUM_SAMPLES];     /* Binary detection */
} sensor_t;

/* ============================ Prototypes ================================ */

static int  read_sensor_file(const char *filename, sensor_t *sensor);
static void generate_detection_signal(sensor_t *sensor);
static void print_intervals(const sensor_t *sensor);
static void print_fused_intervals(const sensor_t *s1,
                                  const sensor_t *s2);

/* ============================ Main ===================================== */

int main(void)
{
    sensor_t sensor1 = {0};
    sensor_t sensor2 = {0};

    sensor1.id        = 1;
    sensor1.threshold = SENSOR1_THRESHOLD;

    sensor2.id        = 2;
    sensor2.threshold = SENSOR2_THRESHOLD;

    if (read_sensor_file("sensor1.txt", &sensor1) != 0)
    {
        return 1;
    }

    if (read_sensor_file("sensor2.txt", &sensor2) != 0)
    {
        return 1;
    }

    generate_detection_signal(&sensor1);
    generate_detection_signal(&sensor2);

    printf("\n--- Object Detection Results ---\n\n");

    printf("Sensor 1 detections:\n");
    print_intervals(&sensor1);

    printf("\nSensor 2 detections:\n");
    print_intervals(&sensor2);

    printf("\nFused signal (both sensors):\n");
    print_fused_intervals(&sensor1, &sensor2);

    return 0;
}

/* ============================ Functions ================================ */

static int read_sensor_file(const char *filename, sensor_t *sensor)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Cannot open %s\n", filename);
        return -1;
    }

    for (uint32_t i = 0U; i < NUM_SAMPLES; ++i)
    {
        if (fscanf(file,
                   "%f %lf",
                   &sensor->data[i].time,
                   &sensor->data[i].probability) != 2)
        {
            printf("Error reading sample %u in %s\n", i, filename);
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return 0;
}

/* ----------------------------------------------------------------------- */

static void generate_detection_signal(sensor_t *sensor)
{
    for (uint32_t i = 0U; i < NUM_SAMPLES; ++i)
    {
        if (sensor->data[i].probability > sensor->threshold)
        {
            sensor->object_detection[i] = 1;
        }
        else
        {
            sensor->object_detection[i] = 0;
        }
    }
}

/* ----------------------------------------------------------------------- */

static void print_intervals(const sensor_t *sensor)
{
    int   in_interval = 0;
    float start_time  = 0.0f;

    for (uint32_t i = 0U; i < NUM_SAMPLES; ++i)
    {
        if ((sensor->object_detection[i] == 1) && (in_interval == 0))
        {
            start_time  = sensor->data[i].time;
            in_interval = 1;
        }

        if ((sensor->object_detection[i] == 0) && (in_interval == 1))
        {
            float end_time = sensor->data[i - 1U].time;
            printf("Start: %.2f s End: %.2f s\n",
                   start_time,
                   end_time);
            in_interval = 0;
        }
    }

    /* Handle case where detection lasts until final sample */
    if (in_interval == 1)
    {
        float end_time = sensor->data[NUM_SAMPLES - 1U].time;
        printf("Start: %.2f s End: %.2f s\n",
               start_time,
               end_time);
    }
}

/* ----------------------------------------------------------------------- */

static void print_fused_intervals(const sensor_t *s1,
                                  const sensor_t *s2)
{
    int   in_interval = 0;
    float start_time  = 0.0f;

    for (uint32_t i = 0U; i < NUM_SAMPLES; ++i)
    {
        int fused = s1->object_detection[i] &
                    s2->object_detection[i];

        if ((fused == 1) && (in_interval == 0))
        {
            start_time  = s1->data[i].time;
            in_interval = 1;
        }

        if ((fused == 0) && (in_interval == 1))
        {
            float end_time = s1->data[i - 1U].time;
            printf("Start: %.2f s End: %.2f s\n",
                   start_time,
                   end_time);
            in_interval = 0;
        }
    }

    if (in_interval == 1)
    {
        float end_time = s1->data[NUM_SAMPLES - 1U].time;
        printf("Start: %.2f s End: %.2f s\n",
               start_time,
               end_time);
    }
}
