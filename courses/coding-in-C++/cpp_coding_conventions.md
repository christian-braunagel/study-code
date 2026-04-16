# C++ Coding Conventions
## Intermediate Guidelines for Second-Semester Students

This document defines a practical set of **C++ coding conventions** for students who already know basic C and now move toward **modular, object-oriented, and safer software development** in C++.

The rules are inspired by professional practice and partially aligned with **safety-oriented ideas** known from standards such as MISRA C++: clear intent, explicit behavior, strong readability, and avoidance of dangerous language features.  
This is **not** a full MISRA document. It is a compact teaching guideline for everyday university work.

The goal is not only “code that works”, but code that is:

- readable
- maintainable
- testable
- explicit
- robust against typical programming errors

---

## 1. General Principles

- Code is written for humans first and for the compiler second.
- Prefer simple and predictable solutions.
- Avoid clever tricks, surprising constructs, and overly compact code.
- Safety and readability are usually more important than saving one line of code.

### Good
```cpp
if (temperature_celsius > MAX_TEMPERATURE_CELSIUS)
{
    shutdown_heater();
}
```

### Bad
```cpp
if (t > 80) shutdown_heater();   // unclear variable name, magic number, no braces
```

---

## 2. Naming Conventions

Use names that describe purpose clearly.

### Rules

- **Variables / parameters:** `lower_snake_case` or `camelCase`
- **Functions / methods:** `lower_snake_case` or `camelCase`, preferably verbs
- **Namespaces:** `lower_snake_case`
- **Constants:** `UPPER_SNAKE_CASE`
- **Classes / structs / enums:** `PascalCase`
- **Pointers:** start with __p___ or __ptr___

**Important: No matter what style you choose: Be consistent in your usage.**

### Good
```cpp
class MotorController
{
private:
    int current_speed_rpm;
public:
    void set_target_speed(int target_speed_rpm);
};

const int MAX_BUFFER_SIZE = 128;
```

### Bad
```cpp
class motorcontroller
{
private:
    int s;
public:
    void st(int x);
};

const int x = 128;
```

---

## 3. Formatting and Layout

Consistency is mandatory.

### Rules

- Use **4 spaces** per indentation level or 1 tab.
- Do **not** mix tabs and spaces.
- Use **one statement per line**.
- Always use braces `{}` for control structures.
- Keep line length roughly below **100 characters**.
- Add one empty line between logical blocks.

### Good
```cpp
for (int index = 0; index < value_count; index++)
{
    process_value(values[index]);
}
```

### Bad
```cpp
for(int i=0;i<value_count;i++) process_value(values[i]);
```

---

## 4. File and Module Structure

As projects grow, source code must be split into modules.

### Rules

- A module usually consists of:
  - one header file (`.hpp`)
  - one source file (`.cpp`)
- Header files declare the interface.
- Source files contain the implementation.
- File names should reflect the contained type or module purpose.

### Good
```cpp
// File: motor_controller.hpp
class MotorController
{
public:
    void start();
};
```

```cpp
// File: motor_controller.cpp
#include "motor_controller.hpp"

void MotorController::start()
{
}
```

### Bad
```cpp
// everything.cpp
// contains 8 unrelated classes and utility functions
```

---

## 5. Header Files

Header files define interfaces and must stay clean.

### Rules

- Use **include guards**
- A header file should contain:
  - declarations
  - type definitions
  - constants
- A header file should generally **not** contain:
  - large implementations
  - unrelated includes
  - global object definitions

### Good
```cpp
#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

class MotorController
{
public:
    void start();
};

#endif
```

### Bad
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

// no include guard

class MotorController
{
public:
    void start()
    {
        std::cout << "Start\n";
    }
};
```

## 6. Comments and Documentation

Comments explain **intent**, assumptions, and design decisions. They should not repeat obvious syntax.

### Rules

- Each source file should begin with a short file header.
- Public functions should be documented including:
   - Return values
   - Parameters
- Explain **why**, not every trivial **what**.
- Below is an **example** on how a function could be documented.

Note: You can select your own style according to the rules above; just be consistent.

### Good
```cpp
/**
 * @brief Calculates the average temperature.
 *
 * Returns the arithmetic mean of all valid sensor values.
 * Invalid sensor values are ignored.
 *
 * @param[in] values       Array of sensor values
 * @param[in] value_count  Number of elements in values
 * @return                 Average of valid values
 */
double calculate_average(const double values[], int value_count);
```

### Bad
```cpp
// increment i
i++;
```

```cpp
// This function calculates something
double calculate_average(const double values[], int value_count);
```

---

## 7. Variables

Variables must be understandable, initialized, and used responsibly.

### Rules

- Initialize variables immediately.
- One variable declaration per line.
- Keep scope as small as possible.
- Each variable should be used at least once.

### Good
```cpp
int retry_count = 0;
double measured_voltage = 0.0;
bool is_system_ready = false;
```

### Bad
```cpp
int a, b, c;
double voltage;
bool flag;
```

```cpp
int timeout_ms = 5000;   // never used
```

---

## 8. Constants and Magic Numbers

Unnamed numbers make code harder to understand.

### Rules

- Replace magic numbers with named constants.
- Choose meaningful names.

### Good
```cpp
const int MAX_LOGIN_ATTEMPTS = 3;

if (attempt_count >= MAX_LOGIN_ATTEMPTS)
{
    lock_account();
}
```

### Bad
```cpp
if (attempt_count >= 3)
{
    lock_account();
}
```

---

## 9. Type Safety

C++ gives many type features. Use them explicitly and carefully.

### Rules

- Prefer exact and appropriate types.
- No implicit narrowing conversions.
- Use `bool` for logical states.
- Prefer `enum class` over plain `enum`.
- Avoid mixing signed and unsigned values carelessly.

### Good
```cpp
enum class MotorState
{
    Stopped,
    Running,
    Error
};

MotorState state = MotorState::Stopped;
```

### Bad
```cpp
enum MotorState
{
    Stopped,
    Running,
    Error
};

int state = 0;
```

### Good
```cpp
double voltage = 12.7;
int rounded_voltage = static_cast<int>(voltage);
```

### Bad
```cpp
int rounded_voltage = voltage;   // implicit conversion
```
---
## 10. Functions

Functions should be small, focused, and easy to test.

### Rules

- One function = one responsibility.
- Keep functions short where practical.
- Function names should describe behavior.
- Parameters should be minimal and meaningful.
- Each function parameter should be used or removed.

### Good
```cpp
int calculate_sum(int first_value, int second_value)
{
    return first_value + second_value;
}
```

### Bad
```cpp
int calc(int a, int b, int c)
{
    return a + b;   // c is unused
}
```

### Good
```cpp
bool is_temperature_valid(double temperature_celsius)
{
    return (temperature_celsius >= -40.0) && (temperature_celsius <= 125.0);
}
```

### Bad
```cpp
bool check(double x)
{
    return x > -40.0 && x < 125.0;   // unclear function name
}
```

---

## 11. Parameter Passing

Choose parameter passing deliberately.

### Rules

- Small fundamental types: pass by value.
- Large objects: pass by reference.
- Large read-only objects: pass by `const` reference.
- Output parameters should be avoided when a return value is clearer.

### Good
```cpp
int increment(int value)
{
    return value + 1;
}

void print_message(const std::string& message);
```

### Bad
```cpp
void print_message(std::string message);   // unnecessary copy
```

### Good
```cpp
void reset_counter(int& counter)
{
    counter = 0;
}
```

### Bad
```cpp
void reset_counter(int counter)   // caller expects change, but gets copy
{
    counter = 0;
}
```

---

## 12. Pointers and References

Pointers are powerful but risky. Use them only when needed.

### Rules

- Prefer references over pointers when null is not a valid state.
- Initialize every pointer.
- Never dereference a pointer without ensuring validity.
- Use `nullptr`, never `NULL` in modern C++.

### Good
```cpp
int value = 5;
int* p_value = &value;

if (p_value != nullptr)
{
    *p_value = 10;
}
```

### Bad
```cpp
int* p_value;
*p_value = 10;   // uninitialized pointer
```

### Good
```cpp
void update_speed(int& speed_rpm)
{
    speed_rpm += 100;
}
```

### Bad
```cpp
void update_speed(int* p_speed_rpm)   // pointer not necessary if null is invalid
{
    *p_speed_rpm += 100;
}
```
---

## 13. Global Variables

Global state makes software harder to understand and test.

### Rules

- Avoid global variables.
- Prefer passing data through parameters or class members.

### Good
```cpp
const int DEFAULT_PORT = 8080;
```

### Bad
```cpp
int g_error_count = 0;
bool g_system_running = false;
```

---

## 14. Control Structures

Control flow must be simple and explicit.

### Rules

- Always use braces.
- Keep nesting shallow.
- Prefer early return over deeply nested `if` blocks where it improves readability.
- Conditions must be easy to understand.

### Good
```cpp
bool process_value(int value)
{
    if (value < 0)
    {
        return false;
    }

    if (value == 0)
    {
        return true;
    }

    return handle_positive_value(value);
}
```

### Bad
```cpp
bool process_value(int value)
{
    if (value >= 0)
    {
        if (value != 0)
        {
            return handle_positive_value(value);
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
```

---

## 15. `if`, `for`, `while`, and `switch`

### Rules

- Keep loop boundaries explicit.
- Avoid complex loop conditions.
- Infinite loops are only allowed when clearly intentional.
- Every `switch` must contain a `default` branch.
- Use `break` intentionally and visibly.

### Good
```cpp
for (int index = 0; index < 10; index++)
{
    process_value(index);
}
```

### Bad
```cpp
for (;;)
{
    process_value(0);   // unclear endless loop
}
```

### Good
```cpp
switch (command)
{
case Command::Start:
    start_motor();
    break;

case Command::Stop:
    stop_motor();
    break;

default:
    report_invalid_command();
    break;
}
```

### Bad
```cpp
switch (command)
{
case Command::Start:
    start_motor();
case Command::Stop:
    stop_motor();
}
```

---

## 16. Expressions

Expressions must remain simple and unambiguous.

### Rules

- Avoid overly complex expressions.
- Do not rely on subtle operator precedence.
- Split complex logic into intermediate variables.

### Good
```cpp
const bool is_in_valid_range =
    (temperature_celsius >= MIN_TEMPERATURE_CELSIUS) &&
    (temperature_celsius <= MAX_TEMPERATURE_CELSIUS);
```

### Bad
```cpp
if (a + b * c - d / e > f && x++ < y--)
{
}
```

---

## 17. Casting

Casting is a warning sign and should be rare.

### Rules

- Avoid C-style casts.
- Prefer C++ casts:
  - `static_cast`
  - `const_cast`
  - `dynamic_cast`
  - `reinterpret_cast`
- Every cast should be justified.
- Never use casts to silence warnings without understanding the issue.

### Good
```cpp
double average = static_cast<double>(sum) / count;
```

### Bad
```cpp
double average = (double)sum / count;
```

### Bad
```cpp
int value = reinterpret_cast<int>(pointer);   // dangerous and usually unjustified
```
---

## 18. Error Handling

Errors must be detected and handled explicitly.

### Rules

- Check return values where applicable.
- Validate function inputs.
- Do not ignore failure cases.
- Error-handling code must be clear and testable.

### Good
```cpp
bool divide(double dividend, double divisor, double& result)
{
    if (divisor == 0.0)
    {
        return false;
    }

    result = dividend / divisor;
    return true;
}
```

### Bad
```cpp
double divide(double dividend, double divisor)
{
    return dividend / divisor;   // division by zero not handled
}
```
---

## 19. Classes and Encapsulation

Classes should protect their internal state and expose a clear interface.

### Rules

- Member variables must generally be `private`.
- Public methods form the interface.
- Methods with more than 5 lines of code should be defined outside of the class.
- A class should have one clear responsibility.

### Good
```cpp
class BankAccount
{
private:
    double m_balance;

public:
    void deposit(double amount);
    double get_balance() const;
};
```

### Bad
```cpp
class BankAccount
{
public:
    double balance;
};
```

---

## 20. Constructors and Initialization

Objects must start in a valid state.

### Rules

- Always initialize all member variables.
- Prefer **member initializer lists**.
- Avoid complex logic in constructors.

### Good
```cpp
class Plane
{
private:
    std::string m_model;
    int m_speed;

public:
    Plane(const std::string& model, int speed)
        : m_model(model), m_speed(speed)
    {
    }
};
```

### Bad
```cpp
class Plane
{
private:
    std::string m_model;
    int m_speed;

public:
    Plane(const std::string& model, int speed)
    {
        m_model = model;
        m_speed = speed;
    }
};
```

---

## 21. `const` Correctness

Use `const` to express read-only intent.

### Rules

- Mark methods as `const` if they do not modify object state.
- Pass large read-only objects by `const` reference.
- Use `const` for variables whose value must not change after initialization.
- `const` increases safety and documents intent.

### Good
```cpp
class Sensor
{
private:
    int m_id;

public:
    int get_id() const
    {
        return m_id;
    }
};

void print_name(const std::string& name);
```

### Bad
```cpp
class Sensor
{
private:
    int m_id;

public:
    int get_id()
    {
        return m_id;
    }
};

void print_name(std::string name);
```

---

## 22. Dynamic Memory

Manual memory management must be minimized.

### Rules

- Prefer automatic storage duration (stack objects) whenever possible.
- Avoid `new` and `delete` unless dynamic lifetime is truly required.
- Every `new` must have exactly one matching `delete`.
- Never mix `new/delete` with `malloc/free`.

### Good
```cpp
Sensor sensor;
```

### Bad
```cpp
Sensor* p_sensor = new Sensor();
// ...
free(p_sensor);   // wrong deallocation mechanism
```

### Good
```cpp
Sensor* p_sensor = new Sensor();
// ...
delete p_sensor;
p_sensor = nullptr;
```

### Bad
```cpp
Sensor* p_sensor = new Sensor();
// forgot delete => memory leak
```

---

## 23. Inheritance

Inheritance is powerful, but it should be used carefully.

### Rules

- Prefer composition over inheritance unless there is a true “is-a” relationship.
- Base classes should have a meaningful abstraction.
- Avoid deep inheritance hierarchies.

### Good
```cpp
class Shape
{
public:
    virtual double calculate_area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
public:
    double calculate_area() const override;
};
```

### Bad
```cpp
class Printer : public Logger : public Device : public BaseObject
{
    // deep and unclear hierarchy
};
```

---

## 24. Virtual Functions and Polymorphism

Use dynamic polymorphism intentionally.

### Rules

- Use `override` for overriding functions.
- A polymorphic base class should usually have a virtual destructor.
- Do not introduce virtual functions unless polymorphism is needed.
- Keep interfaces small and meaningful.

### Good
```cpp
class Animal
{
public:
    virtual void speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void speak() const override;
};
```

### Bad
```cpp
class Animal
{
public:
    virtual void speak() const;
};

class Dog : public Animal
{
public:
    void speak() const;   // missing override
};
```

---

## 25. Static Members

Static members belong to the class, not to an object instance.

### Rules

- Use static data only when shared state is truly required.
- Static methods must not depend on object state.

### Good
```cpp
class Counter
{
private:
    static int m_instance_count;

public:
    Counter()
    {
        m_instance_count++;
    }

    static int get_instance_count()
    {
        return m_instance_count;
    }
};
```

### Bad
```cpp
class Counter
{
public:
    static int value;
    int get_value()
    {
        return value;   // unclear design and poor encapsulation
    }
};
```

---

## 26. Standard Library Usage

Use the C++ standard library consciously.

### Rules

- Prefer `std::string` over raw C strings in normal C++ code.
- Prefer standard containers over manual arrays when appropriate.
- Do not use the keyword __using__ especially in larger projects.

### Good
```cpp
std::string user_name = "Alice";
```

### Bad
```cpp
char user_name[100];
strcpy(user_name, "Alice");
```

---

## 27. Avoid Dangerous or Discouraged Constructs

### Rules

- Do not use `goto`.
- Do not rely on undefined behavior.
- Avoid macros for constants and preprocessor tricks unless absolutely necessary.

### Good
```cpp
const int MAX_RETRY_COUNT = 5;
```

### Bad
```cpp
#define MAX_RETRY_COUNT 5
```

### Bad
```cpp
goto error_handler;
```

---

## 28. Final Advice

- Be consistent.
- Prefer explicit behavior.
- Design interfaces carefully.
- Keep classes and functions small and focused.
- Do not hide complexity behind unclear names.
- Avoid surprising behavior.
- When in doubt, choose the simpler and safer solution.

> Clean C++ code is not just valid syntax.  
> It is code with clear intent, controlled complexity, and predictable behavior.
