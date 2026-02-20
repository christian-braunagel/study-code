#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car {
    float fuel_level;
    float max_fuel_level;
    char model[100];
};


int main() { 
    struct car car1;
    struct car * p_car = &car1;
    float addfuel = 40;
    refuel(p_car);

    struct car mycar = {23, 66, "BMW i30"};
ss
    return 0;
}

void refuel(struct car * mycar) {
    if(mycar->max_fuel_level < mycar->fuel_level + addfuel) { 
        printf("%c", "Not enough space for fuel")
    }
}