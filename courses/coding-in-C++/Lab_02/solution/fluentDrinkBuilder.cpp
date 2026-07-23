/**
 * @file fluent_drink_builder.cpp
 * @brief Simple fluent builder for configuring a drink.
 */

#include <iostream>
#include <string>
#include "fluentDrinkBuilder.hpp"

DrinkBuilder::DrinkBuilder(const std::string &name, int sugar, int temperature, bool withMilk)
    : name(name), sugar(sugar), temperature(temperature), withMilk(withMilk)
{

    if (temperature <= 0)
    {
        this->temperature = DEFAULT_TEMP;
    }

    if (sugar < 0)
    {
        this->sugar = DEFAULT_MIN_SUGAR;
    }
};

DrinkBuilder &DrinkBuilder::setName(const std::string &name)
{
    this->name = name;
    return *this;
}

DrinkBuilder &DrinkBuilder::setSugar(int sugar)
{
    if (sugar >= 0)
    {
        this->sugar = sugar;
    }

    return *this;
}

DrinkBuilder &DrinkBuilder::setTemperature(int temperature)
{
    if (temperature > 0)
    {
        this->temperature = temperature;
    }

    return *this;
}

DrinkBuilder &DrinkBuilder::setWithMilk(bool withMilk)
{
    this->withMilk = withMilk;
    return *this;
}

const DrinkBuilder &DrinkBuilder::print() const
{
    std::cout << "Name: " << this->name << '\n';
    std::cout << "Sugar: " << this->sugar << '\n';
    std::cout << "Temperature: " << this->temperature << '\n';
    std::cout << "With Milk: " << std::boolalpha << this->withMilk << '\n';

    return *this;
}

bool DrinkBuilder::isValid() const
{
    bool valid = true;

    if (this->sugar < 0)
    {
        std::cout << "Hey - you should add more sugar" << '\n';
        valid = false;
    }
    if (this->temperature <= 0)
    {
        std::cout << "I have a sore throat - increase the temperature" << '\n';
        valid = false;
    }

    if (valid)
    {
        std::cout << "That's perfect!" << '\n';
    }

    return valid;
}

int main()
{
    DrinkBuilder drink1("Gin Tonic", 0, 15, false);
    drink1.print();

    std::cout << std::endl;

    drink1.setName("White Russian")
        .setSugar(5)
        .setTemperature(4)
        .setWithMilk(true)
        .print();

    drink1.isValid();
}
