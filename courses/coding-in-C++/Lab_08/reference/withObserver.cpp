#include <iostream>
#include <vector>

// ======================================================
// Observer Interface
// ======================================================

class Observer
{
public:
    virtual void update(float value) = 0;

    virtual ~Observer() = default;
};

// ======================================================
// Subject
// ======================================================

class TemperatureSensor
{
private:
    float temperature = 0.0f;

    std::vector<Observer *> observers;

    void notify_observers()
    {
        for (Observer *observer : observers)
        {
            observer->update(temperature);
        }
    }

public:
    void add_observer(Observer *observer)
    {
        observers.push_back(observer);
    }

    void set_temperature(float value)
    {
        temperature = value;

        notify_observers();
    }
};

// ======================================================
// Concrete Observer: Display
// ======================================================

class Display : public Observer
{
public:
    void update(float value) override
    {
        std::cout << "Display: " << value << " C\n";
    }
};

// ======================================================
// Concrete Observer: Logger
// ======================================================

class Logger : public Observer
{
public:
    void update(float value) override
    {
        std::cout << "Logger: " << value << " C\n";
    }
};

// ======================================================
// Main
// ======================================================

int main()
{
    TemperatureSensor sensor;

    Display display;
    Logger logger;

    sensor.add_observer(&display);
    sensor.add_observer(&logger);

    sensor.set_temperature(23.5f);

    return 0;
}