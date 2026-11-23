/*
 * File: gas_station.c
 * Description: Short exercise to train structs and their handling as pointers.
 */
#include <stdio.h>

typedef struct Car
{
    float max_fuel_level; // in liters
    float fuel_level;     // in liters
    const char *model;

} Car;

/**
 * @brief Refuel/Increase the fuel level of a given car.
 *
 * @param p_car [out] pointer to a car struct
 * @param fuel [in]   amount of fuel to fill into the car
 */
void refuel(Car *p_car, float fuel)
{
    if ((p_car->fuel_level + fuel) > p_car->max_fuel_level)
    {
        printf("Error: The maximum amount of fuel is succeded.");
        return;
    }
    p_car->fuel_level = p_car->fuel_level + fuel;
}

int main()
{

    Car myCar = {60.0, 11.1, "C-Class"};
    refuel(&myCar, 40);

    printf("Fuel level is %f", myCar.fuel_level);
    return 0;
}
