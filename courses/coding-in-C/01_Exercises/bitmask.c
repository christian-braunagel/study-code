#include <stdio.h>

unsigned char sensordata = 0xA7;
unsigned char measurement_data[4];

int main(void){

    unsigned char bit7 = (sensordata & 0x80) >> 7;
    printf("%c", bit7);
    //if sensordata | 0

    return 0;
}