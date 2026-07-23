# Lab 6: Exception Handling & Smart Pointer

This lab focuses on **Exception Handling & Smart Pointer in C++**.

You will practice the following concepts:

* `try`, `throw`, and `catch`
* standard exceptions
* custom exception classes
* unique pointer
* shared pointer


All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: Exception Handling with `ConfigLoader`

In this section you will practice the basics of exception handling in C++.

You will practice the following concepts:

* `try`, `throw`, and `catch`
* standard exceptions
* custom exception classes
* exception propagation

---

### Task Description

Implement a class `ConfigLoader`. This class should have a method `load(filename)`. Your task is to handle different error cases inside the method (the actual logic of the method is irrelevant for this exercise).

* Empty filenames are invalid
* Only file extensions of type `.cfg` are allowed
* An error should be generated if the file cannot be opened
  Simulate this behavior with:

```cpp
filename == "missing.cfg"
```

* An error should be generated if the system-specific configuration is invalid
  Simulate this behavior with:

```cpp
filename == "invalid.cfg"
```

### Requirements

* Use appropriate exceptions (standard exceptions or your own exception classes) to handle these cases.
* Test all error cases in your `main` function.

---

## 🟡 Section II: Smart greenhouse

In this section you will practice exception handling in C++.

You will practice the following concepts:

* `try`, `throw`, and `catch`
* standard exceptions
* custom exception classes
* exception propagation

---

## Task Description

You are part of a software engineering team developing a monitoring system for a smart greenhouse.

The system continuously reads data from different sensors:

* temperature sensors
* humidity sensors
* water level sensors

Some situations indicate severe system problems and should therefore be handled using exceptions:

* a sensor becomes unreachable
* physically impossible measurements are received
* a sensor configuration is corrupted (i.e. minimum limits > maximum limits)
* irrigation is activated although no water is available

The system should use exceptions to detect and handle these exceptional situations.

---

## 🟢 Part 1: Standard Exceptions

Create a class `Sensor`.

The class should contain:

1. sensor name
2. current value
3. minimum physically possible value
4. maximum physically possible value

Add methods:

1. `update_value(double value)`
2. `get_value()`
3. `print_info()`

Rules:

* impossible sensor values should throw `std::out_of_range`
* invalid sensor configurations should throw `std::invalid_argument`

Examples:

* humidity below `0%`
* humidity above `100%`
* temperature below `-273.15°C`

### Testing Exceptions in `main()`

Create three sensors to measure the above mentioned states and intentionally trigger invalid situations.

Use one catch block directly after the try statements in the main to catch each exception.
Use the what-method to output the catched exception message.

### Question
- What would happen to an object if you throw an exception within its constructor?

---

## 🟢 Part 2: Multiple Catch Blocks

Extend your program so that different exception types are handled separately. Moreover, use only one try block for all tests.

Also, all catch-statements should be located together - not being called directly after a try-block.

- Discuss why the order of `catch` blocks matters.
- What is the difference between calling every test case in a separate try block or in one common try block.

---

## 🟡 Part 3: Custom Exception Classes

Create a custom exception class called __SensorFailureError__ representing a specialized form of a runtime error.

It should return the error message ```Sensor is unreachable```.

Then add a method to the Sensor class:

```cpp
simulate_failure()
```

This method should throw `SensorFailureError`.
Catch this exception in `main()`.

---

### Reflection Questions

1. Why are exceptions preferable to integer error codes in this system?
2. Why should exceptions usually be caught by `const` reference?
3. What is the difference between `std::invalid_argument`, `std::runtime_error`, and `std::out_of_range`?
4. When should custom exception classes be used?
5. Why should `catch (const std::exception& e)` usually appear after more specific `catch` blocks?
6. Why should exceptions not be used for normal control flow?
7. What happens if an exception is never caught?

## 🟡 Section III: Smart Pointers

In this section you will practice memory management using smart pointers in C++.

You will practice the following concepts:

* `std::unique_ptr`
* `std::shared_ptr`
* `make_unique` and `make_shared`

---

## Task Description

The goal is to implement parts of a basic streaming platform.
The platform manages different types of media devices:

* speakers
* displays
* microphones

Devices can either:

* belong exclusively to one room
* or be shared between multiple rooms

The system should use smart pointers instead of raw pointers for memory management.

---

## 🟡 Part 1: `std::unique_ptr`

Create a class `Device`.

The class should contain:

1. device name
2. device type
3. power status which is false by default

Add methods:

1. `turn_on()`
2. `turn_off()`
3. `print_info()`

Add a destructor that outputs a message when a device is destroyed.

---

Create a class `Room`.

The class should contain:

1. room name
2. a list container of devices

Rules:

* each device belongs to exactly one room
* devices must be managed using `std::unique_ptr`

Add methods:

1. `add_device(...)`
2. `remove_device_by_name(...)`
3. `print_devices()`

---

### Testing in `main()`

Create multiple rooms.
Create multiple devices owned by unique pointers.

Move devices into rooms and test what happens with the original pointer.

---

## 🟢 Part 2: Ownership Semantics

Answer the following questions by experimenting with code:

1. What happens if you try to copy a `std::unique_ptr`?
2. Why is `std::move(...)` required?
3. What happens to the original pointer after moving?
4. When is the destructor automatically called?

---

## 🔴 Part 3: `std::shared_ptr` and Inheritance

Some devices should be shareable between multiple rooms.

Examples:

- a central music server
- a network storage device

These shared devices are specialized devices with additional network functionality.

Create a class:

```cpp
SharedDevice
```

that inherits from:

```cpp
Device
```

---

## Additional Requirements for `SharedDevice`

The class should additionally contain:

1. IP address
2. network connection status

Add methods:

```cpp
connect_to_network()
disconnect_from_network()
print_network_info()
```

---

## Shared Ownership

Shared devices may belong to multiple rooms simultaneously.

Use:

```cpp
std::shared_ptr
```

to manage shared devices.

---

## Modify the `Room` class

Rooms should now support:

1. exclusive devices (`std::unique_ptr<Device>`)
2. shared devices (`std::shared_ptr<SharedDevice>`)

Add methods:

```cpp
add_shared_device(...)
print_shared_devices()
```

---

## Testing in `main()`

1. Create shared devices using:

```cpp
std::make_shared(...)
```

2. Add the same shared device to multiple rooms.
3. Check the reference counter using:

```cpp
use_count()
```

- after creation
- after adding to rooms
- after rooms are destroyed

---

## Reflection Questions

1. Why are smart pointers safer than raw pointers?
2. What problem does `std::unique_ptr` solve?
3. Why can `std::unique_ptr` not be copied?
4. What problem does `std::shared_ptr` solve?
5. What does `use_count()` represent?
6. Why can cyclic references become problematic with `std::shared_ptr`?
7. Why should the base class destructor be virtual in polymorphic class hierarchies?

## 🔴 Section IV: Bug Hunt & System Extension

In this section you will analyze, debug and extend a larger C++ software system.

You will practice the following concepts:

* debugging and code analysis
* logical and conceptual software errors
* object-oriented design
* STL containers
* smart pointers
* inheritance and polymorphism
* software architecture improvements

---

## Task Description

You are working on driver assistance systems for autonomous vehicles.

The project already contains several components:

* vehicles
* distance sensors
* emergency brake systems
* adaptive cruise control
* lane keeping assistants
* parking assistants

The current implementation compiles successfully, but contains several logical and conceptual problems.

Your task is divided into multiple parts.

---

## 🟡 Part 1: Bug Hunt

Analyze the existing source code and identify all logical or conceptual errors.
Check the following files:
- bugHunt_assistance_system.cpp
- bugHunt_assistance_system.hpp
- bugHunt_vehicle.cpp
- bugHunt_vehicle.hpp
- bugHunt_main.cpp

---

### Requirements

1. Identify all 10 errors in the provided code.
2. Explain why they are problematic.
3. Correct the implementation.

---

### Testing

After fixing the bugs:

* emergency braking should trigger correctly
* adaptive cruise control should slow down when necessary
* steering corrections should behave correctly
* invalid sensor values should be handled properly
* parking assistant warnings should work as expected

---

## 🟡 Part 2: Smart Pointer Refactoring

The current implementation uses raw pointers and references for sensor management.

Refactor the project to use smart pointers instead.

---

### Requirements

The parking assistant but also the other driver assistance systems should safely manage sensor ownership without using raw pointers.
Hence, replace raw pointers with smart pointers.

---

### Additional Tasks

1. Keep the sensors of the parking assistant stored inside STL containers.
2. Add the same front sensor to multiple systems in main.
3. Print the reference counter in main to keep track of the number of owners.

---

## 🟡 Part 3: Polymorphic Assistance Systems

Currently, all assistance systems are implemented independently.

Introduce a common polymorphic base class:

```cpp
class AssistanceFeature
```

with the following public methods:
- void evaluate(Vehicle &vehicle)
- void print_name()
- ~AssistanceFeature()

Decide which of these methods should be virtual, pure virtual or normal functions.

---

### Requirements

The following assistance systems should inherit from this class.

* `EmergencyBrakeSystem`
* `AdaptiveCruiseControl`
* `LaneKeepingAssist`

Store all assistance systems in a container:

```cpp
std::vector<std::unique_ptr<AssistanceFeature>>
```

Execute all systems polymorphically inside a loop in main.
