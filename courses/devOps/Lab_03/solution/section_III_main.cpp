#include <iostream>

int main()
{
    const char* deviceName = "Temperature Control Unit";
    const char* firmwareVersion = "1.0.0";
    double temperatureCelsius = 23.5;
    double voltage = 3.3;

    std::cout << "Device: " << deviceName << '\n';
    std::cout << "Firmware: " << firmwareVersion << '\n';
    std::cout << "Temperature: " << temperatureCelsius << " C" << '\n';
    std::cout << "Voltage: " << voltage << " V" << '\n';
    std::cout << "Status: OK" << '\n';

    return 0;
}
