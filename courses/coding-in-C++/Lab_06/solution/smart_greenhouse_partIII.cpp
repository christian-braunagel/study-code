/**
 * @file smart_greenhouse_partIII.cpp
 * @brief Demonstrates exception handling with standard and custom exception types.
 *
 * This file defines a simple Sensor class with validation logic for
 * sensor configuration and sensor values. It also defines a custom
 * exception class called SensorFailureError, which represents a
 * specialized runtime error for unreachable sensors.
 *
 * The main function demonstrates how different exception types can be
 * handled separately. All test cases are placed inside one common try block,
 * and all catch blocks are grouped together after that try block.
 */

#include <iostream>
#include <stdexcept>
#include <string>

/**
 * @brief Represents a sensor failure as a specialized runtime error.
 *
 * This exception is thrown when a sensor cannot be reached.
 */
class SensorFailureError : public std::runtime_error
{
public:
    /**
     * @brief Constructs a new SensorFailureError object.
     *
     * Initializes the exception with the fixed error message
     * "Sensor is unreachable".
     */
    SensorFailureError()
        : std::runtime_error("Sensor is unreachable")
    {
    }
};

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

    /**
     * @brief Simulates a sensor failure.
     *
     * This method always throws a SensorFailureError to simulate that
     * the sensor is unreachable.
     *
     * @throws SensorFailureError Always thrown when this method is called.
     */
    void simulate_failure()
    {
        throw SensorFailureError();
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
        Sensor failure_sensor("Failure Sensor",
                              TEMPERATURE_INITIAL_VALUE,
                              TEMPERATURE_MIN_VALUE,
                              TEMPERATURE_MAX_VALUE);

        failure_sensor.simulate_failure();

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
    catch (const SensorFailureError &error)
    {
        std::cout << "Sensor failure detected: "
                  << error.what()
                  << std::endl;
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
    catch (const std::runtime_error &error)
    {
        std::cout << "Runtime error: "
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
     * Why are exceptions preferable to integer error codes in this system?
     *
     * Exceptions make error handling clearer because error cases are separated
     * from the normal program logic. They can also carry meaningful error
     * information and cannot be accidentally ignored as easily as integer
     * return codes.
     */

    /*
     * Why should exceptions usually be caught by const reference?
     *
     * Catching by const reference avoids copying the exception object.
     * It also preserves the real dynamic exception type and prevents object
     * slicing. The const keyword makes clear that the catch block should not
     * modify the exception object.
     */

    /*
     * What is the difference between std::invalid_argument,
     * std::runtime_error, and std::out_of_range?
     *
     * std::invalid_argument is used when a function receives an argument that
     * is logically invalid, for example a minimum value greater than a maximum
     * value.
     *
     * std::runtime_error is used for errors that occur during program execution
     * and cannot always be detected before the program runs, for example an
     * unreachable sensor.
     *
     * std::out_of_range is used when a value is outside an allowed range, for
     * example a sensor value below the minimum or above the maximum.
     */

    /*
     * When should custom exception classes be used?
     *
     * Custom exception classes should be used when a program needs to represent
     * a specific error type more precisely than the standard exception classes
     * can. They are useful when the caller should be able to catch and handle
     * this specific error separately.
     */

    /*
     * Why should catch (const std::exception& e) usually appear after more
     * specific catch blocks?
     *
     * C++ checks catch blocks from top to bottom. Since std::exception is the
     * base class of many standard and custom exception types, it would also
     * catch exceptions such as SensorFailureError, std::invalid_argument,
     * std::runtime_error and std::out_of_range.
     *
     * Therefore, the general std::exception catch block should appear last,
     * otherwise the more specific catch blocks would never be reached.
     */

    /*
     * Why should exceptions not be used for normal control flow?
     *
     * Exceptions are intended for unusual error situations, not for expected
     * decisions in normal program logic. Using them for normal control flow
     * makes the code harder to read, harder to debug and can be less efficient
     * than ordinary conditions such as if statements.
     */

    /*
     * What happens if an exception is never caught?
     *
     * If an exception is thrown and no matching catch block is found, the
     * program calls std::terminate. This usually ends the program immediately.
     */

    return 0;
}