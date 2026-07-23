/**
 * @file smart_greenhouse_partI.cpp
 * @brief Demonstrates basic exception handling with a Sensor class.
 *
 * This file defines a simple Sensor class with validation logic for
 * sensor configuration and sensor values. The main function creates
 * several sensors and demonstrates how invalid values and invalid
 * configurations are handled using exceptions.
 */

#include <iostream>
#include <stdexcept>
#include <string>

/**
 * @brief Represents a sensor with a name, current value and allowed range.
 */
class Sensor
{
private:
    std::string name;
    double current_value;
    const double min_value;
    const double max_value;

public:
    /**
     * @brief Constructs a new Sensor object.
     *
     * Initializes the sensor with a name, an initial value and an allowed
     * minimum and maximum value.
     *
     * @param sensor_name Name of the sensor.
     * @param initial_value Initial value of the sensor.
     * @param minimum_value Minimum allowed sensor value.
     * @param maximum_value Maximum allowed sensor value.
     *
     * @throws std::invalid_argument If the minimum value is greater than the maximum value.
     * @throws std::out_of_range If the initial value is outside the allowed range.
     */
    Sensor(const std::string &sensor_name,
           double initial_value,
           double minimum_value,
           double maximum_value)
        : name(sensor_name),
          current_value(initial_value),
          min_value(minimum_value),
          max_value(maximum_value)
    {
        if (minimum_value > maximum_value)
        {
            throw std::invalid_argument(
                "Invalid sensor configuration: minimum value is greater than maximum value");
        }

        update_value(initial_value);
    }

    /**
     * @brief Updates the current sensor value.
     *
     * Checks whether the given value is inside the allowed range.
     * If the value is valid, it becomes the new current sensor value.
     *
     * @param value New sensor value.
     *
     * @throws std::out_of_range If the value is outside the allowed range.
     */
    void update_value(double value)
    {
        if (value < min_value || value > max_value)
        {
            throw std::out_of_range("Impossible sensor value detected");
        }

        current_value = value;
    }

    /**
     * @brief Returns the current sensor value.
     *
     * @return Current sensor value.
     */
    double get_value() const
    {
        return current_value;
    }

    /**
     * @brief Prints information about the sensor.
     *
     * Prints the sensor name, the current value and the allowed value range
     * to the console.
     */
    void print_info() const
    {
        std::cout << "Sensor: " << name << std::endl;
        std::cout << "Current value: " << current_value << std::endl;
        std::cout << "Allowed range: "
                  << min_value << " to "
                  << max_value << std::endl;
    }
};

/**
 * @brief Program entry point.
 *
 * Creates multiple Sensor objects and tests different exception cases.
 * Exceptions are caught and printed to the console.
 *
 * @return 0 if the program terminates successfully.
 */
int main()
{
    constexpr double TEMPERATURE_INITIAL_VALUE = 20.0;
    constexpr double TEMPERATURE_MIN_VALUE = -273.15;
    constexpr double TEMPERATURE_MAX_VALUE = 80.0;
    constexpr double TEMPERATURE_INVALID_VALUE = -500.0;

    constexpr double HUMIDITY_INITIAL_VALUE = 50.0;
    constexpr double HUMIDITY_MIN_VALUE = 0.0;
    constexpr double HUMIDITY_MAX_VALUE = 100.0;
    constexpr double HUMIDITY_INVALID_VALUE = 150.0;

    constexpr double WATER_LEVEL_INITIAL_VALUE = 30.0;
    constexpr double WATER_LEVEL_MIN_VALUE = 0.0;
    constexpr double WATER_LEVEL_MAX_VALUE = 100.0;
    constexpr double WATER_LEVEL_INVALID_VALUE = -10.0;

    constexpr double INVALID_SENSOR_INITIAL_VALUE = 10.0;
    constexpr double INVALID_SENSOR_MIN_VALUE = 100.0;
    constexpr double INVALID_SENSOR_MAX_VALUE = 0.0;

    try
    {
        Sensor temperature_sensor("Temperature Sensor",
                                  TEMPERATURE_INITIAL_VALUE,
                                  TEMPERATURE_MIN_VALUE,
                                  TEMPERATURE_MAX_VALUE);

        temperature_sensor.update_value(TEMPERATURE_INVALID_VALUE);
    }
    catch (const std::exception &error)
    {
        std::cout << "Temperature error: "
                  << error.what()
                  << std::endl;
    }

    try
    {
        Sensor humidity_sensor("Humidity Sensor",
                               HUMIDITY_INITIAL_VALUE,
                               HUMIDITY_MIN_VALUE,
                               HUMIDITY_MAX_VALUE);

        humidity_sensor.update_value(HUMIDITY_INVALID_VALUE);
    }
    catch (const std::exception &error)
    {
        std::cout << "Humidity error: "
                  << error.what()
                  << std::endl;
    }

    try
    {
        Sensor water_level_sensor("Water Level Sensor",
                                  WATER_LEVEL_INITIAL_VALUE,
                                  WATER_LEVEL_MIN_VALUE,
                                  WATER_LEVEL_MAX_VALUE);

        water_level_sensor.update_value(WATER_LEVEL_INVALID_VALUE);
    }
    catch (const std::exception &error)
    {
        std::cout << "Water level error: "
                  << error.what()
                  << std::endl;
    }

    try
    {
        Sensor invalid_sensor("Invalid Sensor",
                              INVALID_SENSOR_INITIAL_VALUE,
                              INVALID_SENSOR_MIN_VALUE,
                              INVALID_SENSOR_MAX_VALUE);
    }
    catch (const std::exception &error)
    {
        std::cout << "Configuration error: "
                  << error.what()
                  << std::endl;
    }

    return 0;
}