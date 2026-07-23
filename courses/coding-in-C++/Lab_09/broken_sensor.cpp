#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

struct SensorReading
{
    std::string sensor_name;
    std::string unit;
    double value;
};

template <typename T>
T calculate_average(const std::vector<T> &values)
{
    T sum = std::accumulate(values.begin(), values.end(), 0);
    return sum / values.size();
}

template <typename T>
T find_largest_value(const std::vector<T> &values)
{
    return std::max(values.begin(), values.end());
}

std::vector<SensorReading> filter_by_unit(
    const std::vector<SensorReading> &readings,
    const std::string &unit)
{
    std::vector<SensorReading> result;

    std::copy_if(
        readings.begin(),
        readings.end(),
        result.begin(),
        [unit](const SensorReading &reading)
        {
            return reading.unit == unit;
        });

    return result;
}

std::map<std::string, std::vector<double>> group_values_by_sensor(
    const std::vector<SensorReading> &readings)
{
    std::map<std::string, std::vector<double>> grouped_values;

    for (const SensorReading &reading : readings)
    {
        grouped_values[reading.sensor_name].push_back(reading);
    }

    return grouped_values;
}

void print_sensor_summary(
    const std::map<std::string, std::vector<double>> &grouped_values)
{
    for (const auto &[sensor_name, values] : grouped_values)
    {
        std::cout << sensor_name << ": ";
        std::cout << "average = " << calculate_average(values) << ", ";
        std::cout << "max = " << find_largest_value(values) << '\n';
    }
}

int main()
{
    std::vector<SensorReading> readings{
        {"temperature_1", "C", 21.5},
        {"temperature_1", "C", 22.1},
        {"temperature_2", "C", 20.8},
        {"pressure_1", "bar", 1.2},
        {"pressure_1", "bar", 1.4},
        {"humidity_1", "%", 45.0}};

    auto temperature_readings = filter_by_unit(readings, "C");
    auto grouped_values = group_values_by_sensor(temperature_readings);

    print_sensor_summary(grouped_values);

    return 0;
}