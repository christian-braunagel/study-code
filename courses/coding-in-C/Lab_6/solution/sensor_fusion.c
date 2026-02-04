/*
 * File: sensor_fusion.c
 * Description: Program reads and analyzes signals of two sensors for object detection.
 *              The data is provided via two separate text files in this Lab.
 */

#include <stdio.h>

#define SAMPLE_SIZE 3000
#define MAX_INTERVALS 100

typedef struct
{
    float time;
    double probability;
} SensorData;

typedef struct
{
    int id;
    double threshold;
    int object_detection[SAMPLE_SIZE];
    SensorData data[SAMPLE_SIZE];
} Sensor;

/**
 * @brief Read sensor data from files.
 *
 * @param p_filename pointer to filename
 * @param p_sensor   pointer to sensor data container
 * @return           error code (-1 for error)
 */
int read_sensor_data(const char *p_filename, Sensor *p_sensor)
{
    FILE *p_file = fopen(p_filename, "r");

    if (p_file == NULL)
    {
        printf("Error: Could not open file %s\n", p_filename);
        return -1;
    }

    int i = 0;
    while (i < SAMPLE_SIZE)
    {
        if (fscanf(p_file, "%f %lf", &p_sensor->data[i].time, &p_sensor->data[i].probability) != 2)
        {
            printf("Incorrect file format detected or insufficient data. Stopping program.\n");
            fclose(p_file);
            return -1;
        }
        i++;
    }

    fclose(p_file);

    return 0;
}

/**
 * @brief Compare sensor signal with the threshold and return object detection signal.
 *
 * @param p_sensor   pointer to sensor data
 */
void get_object_detection(Sensor *p_sensor)
{
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        if (p_sensor->data[i].probability > p_sensor->threshold)
        {
            p_sensor->object_detection[i] = 1;
        }
        else
        {
            p_sensor->object_detection[i] = 0;
        }
    }

    return;
}

/**
 * @brief Fuse two binary signals
 *
 * @param sensor1_detection   array of int containing detection signal of sensor1
 * @param sensor2_detection   array of int containing detection signal of sensor2
 */
void fusing_sensors(int sensor1_detection[], int sensor2_detection[], int fusion[])
{
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        fusion[i] = sensor1_detection[i] && sensor2_detection[i];
    }
    return;
}

/**
 * @brief Find for a given signal the start and end points of the detection intervals (signal == 1) and call print
 *
 * @param starts              array of float containing interval starting points
 * @param ends                array of float containing interval ending points
 * @param label               name of the signal or sensor
 */
void print_interval(float starts[], float ends[], const char *label)
{
    int i = 0;
    printf("%s detections: ", label);

    while (starts[i] >= 0)
    {
        printf("Start: %.2f s End: %.2f s ", starts[i], ends[i]);
        i++;
    }
    printf("\n");
    return;
}

/**
 * @brief Find for a given signal the start and end points of the detection intervals (signal == 1) and call print
 *
 * @param signal              array of int containing detection signal
 * @param data                array of SensorData; needed for the timestamps
 * @param label               name of the signal or sensor
 */
void detect_intervals(int signal[], SensorData data[], const char *label)
{

    int active = 0;
    float starts[MAX_INTERVALS] = {[0 ... MAX_INTERVALS - 1] = -1}; // NOTE! Only works with Standard version C99+ (should be standard for GCC or Clang)
    float ends[MAX_INTERVALS] = {[0 ... MAX_INTERVALS - 1] = -1};   // NOTE! Only works with Standard version C99+ (should be standard for GCC or Clang)
    int starts_cnt = 0;
    int ends_cnt = 0;

    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        if (signal[i] > 0 && !active)
        {
            if (starts_cnt < MAX_INTERVALS)
            {
                active = 1;
                starts[starts_cnt] = data[i].time;
                starts_cnt++;
            }
        }
        else if (signal[i] < 1 && active)
        {
            if (ends_cnt < MAX_INTERVALS)
            {
                active = 0;
                ends[ends_cnt] = data[i - 1].time;
                ends_cnt++;
            }
        }
    }
    if (starts_cnt > ends_cnt && ends_cnt < MAX_INTERVALS)
    {
        ends[ends_cnt] = data[SAMPLE_SIZE - 1].time;
    }
    print_interval(starts, ends, label);
    return;
}

/**
 * @brief exemplary usage of the sensor fusion functionality
 *
 * @return int status code
 */
int main(int argc, char const *argv[])
{
    Sensor sensor1 = {1, 0.8};
    Sensor sensor2 = {2, 0.7};
    int fusion[SAMPLE_SIZE];

    if (read_sensor_data("../sensor1.txt", &sensor1) < 0)
    {
        return -1;
    }
    if (read_sensor_data("../sensor2.txt", &sensor2) < 0)
    {
        return -1;
    };

    get_object_detection(&sensor1);
    get_object_detection(&sensor2);

    fusing_sensors(sensor1.object_detection, sensor2.object_detection, fusion);

    detect_intervals(sensor1.object_detection, sensor1.data, "Sensor 1");
    detect_intervals(sensor2.object_detection, sensor2.data, "Sensor 2");
    detect_intervals(fusion, sensor1.data, "Fused signal (both sensors)");

    return 0;
}
