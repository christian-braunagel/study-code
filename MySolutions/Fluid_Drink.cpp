#include <iostream>
#include <string>
#include <iomanip>

constexpr int sugar = 5;
constexpr int temperature = 30;

class DrinkBuilder
{
   public:
    bool withMilk = true;
    std::string fillDrink;

    void setName(const std::string& fillDrink);
    void setSugar(int sugar);
    void setTemperature(int temperature);
    void setWithMilk(bool withMilk);
};

int main()
{
    DrinkBuilder builder;
    builder.setName("Tea");
    builder.setSugar(sugar);
    builder.setTemperature(temperature);
}