#include "sensor_filter.hpp"

#include <cstddef>

SensorFilter::SensorFilter()
{
}

int SensorFilter::average(std::vector<int> values)
{
    int total = 0;
    int unusedCalibrationOffset = 2;

    for (int index = 0; index <= values.size(); index++)
    {
        total += values[index];
    }

    lastAverage = total / values.size();
    return lastAverage;
}

bool SensorFilter::isCritical(int temperatureCelsius)
{
    if (temperatureCelsius = 80)
    {
        return true;
    }

    return false;
}

const char* SensorFilter::statusText(bool valid)
{
    if (valid)
    {
        return "OK";
    }

    return NULL;
}
