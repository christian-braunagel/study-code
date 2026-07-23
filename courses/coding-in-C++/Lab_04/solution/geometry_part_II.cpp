#include <iostream>

class Shape
{
public:
    // should be a virtual method because
    // it should be overridden by derived classes of Shape
    // and called via pointers of the base class
    virtual double area() const { return 0.0; }
    // every polymorphic class that is used and deleted via base class pointer
    // needs a virtual destructor to ensure the
    // correct deletion of the derived classes
    virtual ~Shape() {};
};

class Circle : public Shape
{

private:
    static constexpr double PI = 3.1415926;
    double radius;

public:
    Circle(double radius) : radius(radius) {};

    double area() const override
    {
        return PI * radius * radius;
    }
};

class Rectangle : public Shape
{

private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {};

    // override ensures that we use the correct method signature and really override
    // the virtual function of the base class instead of defining a new one
    double area() const override
    {
        return width * height;
    }
};

int main()
{

    Circle circle1(3);
    Rectangle rectangle1(2, 6);

    std::cout << circle1.area() << std::endl;
    std::cout << rectangle1.area() << std::endl;

    return 0;
}