#include <iostream>
#include <cstdint>

namespace __validation__ 
{
    bool isAdult(std::uint8_t age) 
    {
        return age >= 18;
    }

    bool isSenior(std::uint8_t age) 
    {
        return age >= 65;
    }
}

int main() 
{
    std::uint8_t age;

    while (true) 
    {
        std::cout << "Please enter your age: ";

        int input;
        std::cin >> input;
    
        if (input < 0 || input > 115) 
        {
            std::cout << "You did not enter a valid number. Please try again." << std::endl;
            continue;
        } 

        age = static_cast<std::uint8_t> (input);
        break;
    }

    std::cout << "You are " << static_cast<int>(age) << " years old." << std::endl;

    if (__validation__::isSenior(age)) 
    {
        std::cout << "That means that you are a senior citizen." << std::endl;
    } 
    else if (__validation__::isAdult(age)) 
    {
        std::cout << "That means that you are an adult." << std::endl;
    } 
    else 
    {
        std::cout << "That means that you are still a kid or teenager." << std::endl;
    }

    return 0;
}