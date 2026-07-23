/*
 * File: age_validator.cpp
 * Description: Program to classify your age
 */

#include <iostream>
#include <cstdint>
#include <limits>

// namespace includes functions to classify age range
namespace validation
{
    const std::uint8_t ADULT_AGE_LIMIT = 18;
    const std::uint8_t SENIOR_AGE_LIMIT = 65;

    /**
     * @brief Checks whether the given age is considered adult.
     *
     * @param[in] age  Age value to classify
     * @return         true if age is at least ADULT_AGE_LIMIT, otherwise false
     */
    bool isAdult(std::uint8_t age)
    {
        return age >= ADULT_AGE_LIMIT;
    }

    /**
     * @brief Checks whether the given age is considered senior.
     *
     * @param[in] age  Age value to classify
     * @return         true if age is at least SENIOR_AGE_LIMIT, otherwise false
     */
    bool isSenior(std::uint8_t age)
    {
        return age >= SENIOR_AGE_LIMIT;
    }
}

int main()
{
    const int MAX_AGE = 150;
    int age = 0;
    /* Why we do not use std::uint8_t here?
     * std::uint8_t is usually an alias for unsigned char
     * Hence, the first number entered would be converted into an ASCII code
     * and so the code would not work. Moreover, whenever printed to the console
     * the character is shown not the number.
     *
     * Other options would be: Use an integer instead and then cast to:
     * std::uint16_t or std::uint32_t increasing the needed storage
     * std::uint_least16_t ensuring the minimum size of 16 Bit
     * std::uint_fast16_t ensuring using the most efficient data type for the cpu
     */

    std::cout << "Please enter your age: ";
    while (true)
    {
        // if not a number or to large for int
        if (!(std::cin >> age)) // please do not use something like std::cin >> reinterpret_cast<unsigned int&>(age);
        {
            std::cout << "You did not enter a valid number. Please try again." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // no negative numbers allowed
        else if (age < 0)
        {
            std::cout << "You did enter a negative age. Please try again." << '\n';
        }
        else if (age > MAX_AGE)
        {
            std::cout << "The maximum number is: " << static_cast<int>(MAX_AGE) << ". Please try again." << '\n';
        }
        else
        {
            // valid input stops infinity loop
            break;
        }
        std::cout << "Please enter your age: ";
    }

    std::cout << "You are " << age << " years old." << std::endl;

    const std::uint8_t validated_age = static_cast<std::uint8_t>(age);

    if (validation::isSenior(validated_age))
    {

        std::cout << "That means that you are a senior citizen." << std::endl;
    }
    else if (validation::isAdult(validated_age))
    {
        std::cout << "That means that you are an adult." << std::endl;
    }
    else
    {
        std::cout << "That means that you are still a kid or teenager." << std::endl;
    }

    return 0;
}