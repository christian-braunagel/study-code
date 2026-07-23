#include <iostream>

class Shape
{
public:
    // area() is a pure virtual function
    // which makes Shape an abstract class
    // Pure virtual functions need to be implemented
    // in derived classes or the derived class
    // becomes abstract too.
    virtual double area() const = 0;
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

    constexpr int SIZE = 4;

    Circle circle1(3);
    Rectangle rectangle1(2, 6);
    Circle circle2(8);
    Rectangle rectangle2(2, 2);

    Shape *array[SIZE] = {&circle1, &rectangle1, &circle2, &rectangle2};

    for (int i = 0; i < SIZE; i++)
    {
        // Although all objects are accessed through pointers of type Shape*,
        // the correct area() implementation of the actual object type is called.

        // This means the method call is resolved at runtime (dynamic binding)
        // based on the dynamic type of the object, not the static type of the pointer.
        std::cout << array[i]->area() << std::endl;
    }

    return 0;
}

// Reflection Questions

// What is the purpose of the virtual keyword?
// The virtual keyword enables dynamic binding.
// This means the function call is resolved at runtime
// based on the actual (dynamic) type of the object.

// What is the difference between overriding and overloading?
// Overriding: A derived class provides a new implementation
// of a virtual function with the same signature.
// Overloading: Multiple functions have the same name but
// different parameter lists within the same scope.

// What is a pure virtual function?
// A pure virtual function is declared with "= 0" and has
// no implementation in the base class.
// It forces derived classes to implement the function
// and makes the class abstract.

// Why are abstract classes useful?
// Abstract classes define a common interface and cannot be instantiated.
// They ensure that derived classes implement required functionality,
// leading to better design, consistency, and extensibility.