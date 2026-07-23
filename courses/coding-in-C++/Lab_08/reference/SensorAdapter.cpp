#include <iostream>

// Target interface
class Sensor
{
public:
    virtual ~Sensor() = default;

    virtual double read_value() const = 0;
};

// Incompatible class
class LegacyTemperatureDevice
{
public:
    double getTemperature() const
    {
        return 23.5;
    }
};

// Adapter class
class TemperatureAdapter : public Sensor
{

private:
    const LegacyTemperatureDevice &device;

public:
    TemperatureAdapter(const LegacyTemperatureDevice &device)
        : device(device)
    {
    }

    double read_value() const override
    {
        return device.getTemperature();
    }
};

int main()
{
    LegacyTemperatureDevice legacy_device;

    TemperatureAdapter adapter(legacy_device);

    Sensor *sensor = &adapter;

    std::cout << sensor->read_value() << "\n";
}