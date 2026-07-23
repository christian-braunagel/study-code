# Lab 4: Polymorphism in C++

This lab focuses on understanding **polymorphism** in C++.

All the following sections of this lab are based on the following levels of difficulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟡 Section I: Static Polymorphism - Function and Operator Overloading

In this section you will implement a mathematical **2D vector class** and practice different types of **overloading techniques** which represent a static form of polymorphism.

You will practice the following concepts:

- function overloading  
- operator overloading (member vs free functions)   

---

### 🧩 Task Description

You are asked to implement a class `Vector2D` representing a 2D vector.

The class should support common mathematical operations such as vector addition, subtraction, scaling, and comparison. The goal is to design the class interface yourself and apply overloading where appropriate.

---

### 🟢 Part 1 – Basic Class

Create a class called Vector2D which contains:
1. **x** and **y** coordinates (type: double)
2. a default constructor
3. a parameterized constructor to set the coordinates
4. two getter methods for the coordinates
5. a print function that outputs the coordinates of the vector

---

### 🟢 Part 2 – Function Overloading

Implement a method that computes the length (magnitude) of the vector.

- Provide one version that returns the exact length
- Provide a second overloaded version that returns the length rounded to a specified number of decimal places
- Test both versions of the method in the main function

Use the ```round``` function of ```<cmath>``` for this purpose:
```c++
    double factor = std::pow(10.0, precision);
    return std::round(value * factor) / factor;
```

---

### 🟡 Part 3 – Operator Overloading

Implement operator overloading for basic vector operations.

Your class should support:

1. adding two vectors
2. adding another vector to the current object (+=)
3. scalar multiplication in both orders (vector * scalar and scalar * vector)
4. print a vector using standard output streams

Test all operators in `main`

Decide:

- which operator should return a new object or modify the existing object
- which operator should be defined as member or free function 

---

### 🟢 Part 4 – Comparison Operators

Enable comparison between two vectors.

- Implement equality and inequality checks
- Implement these checks independent of each other
- Test the comparison operators in the main function

Consider the challenges of comparing floating-point values.


## 🟢 Section II: Introduction to dynamic Polymorphism

In this section you will learn the basics of **runtime polymorphism** using **virtual functions** and **abstract classes**.

You will practice the following concepts:

- virtual functions  
- overriding functions  
- abstract classes  
- pure virtual functions  

---

### 🧩 Task Description

You will implement a simple class hierarchy for geometric shapes.

---

### 📘 Requirements

### Part 1 – Base Class

Create a base class that represents a general geometric shape.

- The class should define a method that computes the area
- This method should just return a default value (0.0)
- Think about whether this function should be declared as virtual and why. Write a comment.
- Think about whether this class needs a destructor and if so, what kind of destructor. Write a comment.

---

### Part 2 – Derived Classes

Create two specific shapes (Circle and Rectangle) that inherit from your base class.

- Each shape should store the necessary attributes
- Each shape should provide its own implementation of the area calculation
- Make sure the function in the derived classes correctly overrides the base class function
- Test all derived classes in the main function
- Explain if and why the usage of ```override``` makes sense in this scenario


---

### Part 3 – Polymorphism

- Create an array of type `Shape*`
- Assign it 4 objects of your derived classes (two per class)
- Call the `area()` method of each obejct within a loop and print the result
- What do you notice with respect to the called method? Discuss.

---

### Part 4 – Abstract Class

- Modify `Shape` by making it an abstract class
- Explain what changes!

---

### 🧠 Reflection Questions

1. What is the purpose of the `virtual` keyword?  
2. What is the difference between overriding and overloading?  
3. What is a pure virtual function?  
4. Why are abstract classes useful?  

## 🟢 Section III: Bug Hunt: Polymorpher Media Player

### 🧩 Task Description

A media player is supposed to play different audio formats, such as `MP3` and `WAV`.

The implementation contains several errors related to dynamic polymorphism.

👉 Your tasks:

1. What is the program output and why is it not correct?
2. Find at least **4 errors**.
3. Correct the code.

```C++
#include <iostream>
#include <string>

class AudioFile
{
public:
    void play() const
    {
        std::cout << "Playing generic audio file\n";
    }

    virtual void print_info() const
    {
        std::cout << "Generic audio file\n";
    }

    ~AudioFile()
    {
        std::cout << "AudioFile destroyed\n";
    }
};

class MP3File : public AudioFile
{
private:
    std::string artist;

public:
    MP3File(const std::string& artist_name)
        : artist(artist_name)
    {
    }

    void play()
    {
        std::cout << "Playing MP3 by " << artist << "\n";
    }

    void print_info()
    {
        std::cout << "MP3 file by " << artist << "\n";
    }

    ~MP3File()
    {
        std::cout << "MP3File destroyed\n";
    }
};

class WAVFile : public AudioFile
{
public:
    void play() const
    {
        std::cout << "Playing WAV file\n";
    }

    void print_info() const
    {
        std::cout << "Uncompressed WAV file\n";
    }

    ~WAVFile()
    {
        std::cout << "WAVFile destroyed\n";
    }
};

int main()
{
    AudioFile* playlist[2];

    playlist[0] = new MP3File("Daft Punk");
    playlist[1] = new WAVFile();

    for (int index = 0; index < 2; index++)
    {
        playlist[index]->print_info();
        playlist[index]->play();
    }

    for (int index = 0; index < 2; index++)
    {
        delete playlist[index];
    }

    return 0;
}
```

## 🔴 Section IV: Production System: Quality Control Pipeline

### 🧩 Task Description

You are working in a **modern manufacturing plant** for engines where products are automatically inspected before leaving the production line.

Each product must pass through a **quality control pipeline** consisting of different inspection steps.

The system must be flexible because:

- new inspections are added frequently
- different products require different inspections
- some inspections share common behavior

At the moment, three inspections exist:

- **Weight Check**  
  Checks whether the product weight is within a tolerance.

- **Visual Inspection**  
  Checks whether visible defects were detected.

- **Temperature Test**  
  Checks whether the product temperature is within limits.

Beside the capability to perform the inspection, each inspection can create a report including:
- type of inspection
- success or failure of the last performed inspection
- total success-rate of all performed inspections

Since this report mechanism is used by other processes and test engineers, it needs to be like a contract, so that it **guarantees**
that it always behaves/is called in the same way by whichever class uses it.

Each product has a product ID, name and may provide different measurable values such as:
  - weight
  - temperature
  - voltage
  - visual defect status

Depending on these measurable values, the corresponding inspections are performed.

The plant produces 2 products at the moment:
1. A combustion engine (including weight, temperature, visual defect status)
2. An electric engine (including weight, temperature, voltage, visual defect status)

The products can also create a report based on the performed checks. Example output:

```text
Product: Combustion Motor 
- Weight Check: PASS
- Temperature Test: FAIL
- Visual Inspection: PASS

Final Result: REJECTED
```

Your task is to design and implement a system that models this **quality control pipeline**.

You must first create a **UML class diagram** and then implement the design in C++.

---


### 📘 Requirements

Your solution must contain:

1. at least **one abstract class**
2. at least **one interface**
3. at least **two concrete products**
4. at least **three concrete inspections**
5. a pipeline that stores and executes inspections polymorphically (no fake-polymorphism)

---

### 📌 UML Design Task

Create a UML class diagram that shows:

- all classes and interfaces
- inheritance and other relationships
- important attributes
- important methods
- abstract classes and methods

---


### 💻 Implementation Task

Implement your UML design in C++.

Your main program should:

1. create 2 objects of each product and store them in one common array
2. perform all necessary inspections on each object
3. use pointers or references to access the objects
4. print the report for each product object
5. print the report for each inspection type at the end of the program 

---

### 🧠 Reflection Questions

1. Which class in your design is abstract and why?
2. Which interface did you use and what contract does it define?
3. A new inspection is needed to check the voltage. How does your design support adding the new inspection?
