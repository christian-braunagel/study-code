/**
 * @file fluentDrinkBuilder.hpp
 * @brief Declaration of the DrinkBuilder class for configuring drinks
 *        with a fluent interface.
 *
 * The class allows step-by-step modification of a drink configuration
 * using method chaining. It also provides validation and formatted output
 * of the current configuration.
 */

#ifndef FLUENT_DRINK_BUILDER_HPP
#define FLUENT_DRINK_BUILDER_HPP

#include <string>

constexpr int DEFAULT_TEMP = 12;
constexpr int DEFAULT_MIN_SUGAR = 0;

class DrinkBuilder
{
private:
    std::string name;
    int sugar;
    int temperature = DEFAULT_TEMP;
    bool withMilk;

public:
    /**
     * @brief Constructs a DrinkBuilder with initial values.
     *
     * Initializes all attributes with given parameters.
     *
     * @param[in] name            Name of the drink
     * @param[in] sugar           Number of sugar units
     * @param[in] temperature     Temperature in degrees Celsius
     * @param[in] with_milk       Indicates if milk is added
     */
    DrinkBuilder(const std::string &name, int sugar, int temperature, bool withMilk);
    /**
     * @brief Sets the name of the drink.
     *
     * @param[in] name  New drink name
     * @return          Reference to current object for chaining
     */
    DrinkBuilder &setName(const std::string &name);

    /**
     * @brief Sets the sugar amount.
     *
     * @param[in] sugar  Sugar units (must be >= 0)
     * @return           Reference to current object for chaining
     */
    DrinkBuilder &setSugar(int sugar);

    /**
     * @brief Sets the drink temperature.
     *
     * @param[in] temperature  Temperature in °C (must be > 0)
     * @return                 Reference to current object for chaining
     */
    DrinkBuilder &setTemperature(int temperature);

    /**
     * @brief Enables or disables milk.
     *
     * @param[in] with_milk  True if milk should be added
     * @return               Reference to current object for chaining
     */
    DrinkBuilder &setWithMilk(bool withMilk);

    /**
     * @brief Prints the current drink configuration in a readable format.
     *
     * This method returns a reference to the current object so that
     * formatted output can be integrated into a method chain.
     *
     * @return Reference to the current object
     */
    const DrinkBuilder &print() const;

    /**
     * @brief Checks whether the current drink configuration is valid.
     *
     * A configuration is considered valid if the sugar amount is not negative
     * and the temperature is greater than zero.
     *
     * @return True if the configuration is valid, otherwise false
     */
    bool isValid() const;
};

#endif