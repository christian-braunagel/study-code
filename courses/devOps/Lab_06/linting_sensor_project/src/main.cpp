#include "sensor_filter.hpp"

#include <iostream>
#include <vector>

int main()
{
    SensorFilter filter;
    std::vector<int> temperatures = { 21, 22, 85, 23 };

    int averageTemperature = filter.average(temperatures);
    std::cout << "Average temperature: " << averageTemperature << "\n";

    if (filter.isCritical(averageTemperature))
    {
        std::cout << "Status: " << filter.statusText(false) << "\n";
    }

    return 0;
}
