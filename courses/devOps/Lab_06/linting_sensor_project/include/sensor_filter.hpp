#ifndef SENSOR_FILTER_HPP
#define SENSOR_FILTER_HPP

#include <string>
#include <vector>

struct SensorReading
{
    std::string sensorName;
    int rawValue;
    bool valid;
};

class SensorFilter
{
  public:
    SensorFilter();

    int average(std::vector<int> values);
    bool isCritical(int temperatureCelsius);
    const char* statusText(bool valid);

  private:
    int lastAverage;
};

#endif
