/**
 * @file smart_greenhouse_partII.cpp
 * @brief Demonstrates exception handling with a Sensor class.
 *
 * This file defines a simple Sensor class with validation logic for
 * sensor configuration and sensor values. The main function demonstrates
 * how different exception types can be handled separately.
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
 * Creates several Sensor objects and handles different exception types
 * separately using one common try block.
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

        Sensor humidity_sensor("Humidity Sensor",
                               HUMIDITY_INITIAL_VALUE,
                               HUMIDITY_MIN_VALUE,
                               HUMIDITY_MAX_VALUE);

        humidity_sensor.update_value(HUMIDITY_INVALID_VALUE);

        Sensor water_level_sensor("Water Level Sensor",
                                  WATER_LEVEL_INITIAL_VALUE,
                                  WATER_LEVEL_MIN_VALUE,
                                  WATER_LEVEL_MAX_VALUE);

        water_level_sensor.update_value(WATER_LEVEL_INVALID_VALUE);

        Sensor invalid_sensor("Invalid Sensor",
                              INVALID_SENSOR_INITIAL_VALUE,
                              INVALID_SENSOR_MIN_VALUE,
                              INVALID_SENSOR_MAX_VALUE);
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << "Configuration error: "
                  << error.what()
                  << std::endl;
    }
    catch (const std::out_of_range &error)
    {
        std::cout << "Sensor value error: "
                  << error.what()
                  << std::endl;
    }
    catch (const std::exception &error)
    {
        std::cout << "General error: "
                  << error.what()
                  << std::endl;
    }

    /*
     * Why does the order of catch blocks matter?
     *
     * C++ checks catch blocks from top to bottom. The first matching catch block
     * is executed. Therefore, more specific exception types must be caught before
     * more general exception types.
     *
     * For example, std::invalid_argument and std::out_of_range both inherit from
     * std::exception. If catch (const std::exception &error) were placed first,
     * it would also catch invalid_argument and out_of_range. The more specific
     * catch blocks would then never be reached.
     */

    /*
     * What is the difference between using separate try blocks and one common try block?
     *
     * With separate try blocks, every test case is executed independently. If one
     * test throws an exception, only this test is stopped. After the matching catch
     * block, the program continues with the next test case.
     *
     * With one common try block, the first thrown exception immediately leaves the
     * complete try block. All following test cases inside that try block are skipped.
     * This is useful to demonstrate central exception handling, but it is not ideal
     * if every test case should be executed in one program run.
     */

    return 0;
}