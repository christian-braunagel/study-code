# Simple C Coding Guidelines for First-Semester Students (Embedded-Oriented)

This document provides **basic, beginner-friendly rules** for writing **clean, readable, and reliable C code**.  
The guidelines are inspired by professional standards (e.g. MISRA C) but **simplified for learning purposes**.

The goal is **clarity, safety, and good habits** — not maximum performance or advanced hardware features.

---

## 1. General Principles

- Code is read **more often than it is written**
- Prefer **simple and explicit** solutions
- Avoid clever tricks
- If something is unclear, rewrite it

> A program that works but is unreadable is *not* good code.

---

## 2. Naming Conventions

### 2.1 Variables

- Use **meaningful names**
- Use **lowercase letters** and **underscores**
- Avoid single-letter names (except loop counters)

**Good:**
```c
int temperature_celsius;
float motor_speed;
```

**Bad:**
```c
int x;
float ms;
```

---

### 2.2 Constants

- Use `const` for values that do not change
- Use **uppercase names** with underscores

```c
const int MAX_ATTEMPTS = 3;
const float PI = 3.14159f;
```

---

### 2.3 Functions

- Use verbs in function names
- Describe *what the function does*

```c
void init_system(void);
int calculate_sum(int a, int b);
```

---

## 3. Code Formatting and Structure

### 3.1 Indentation

- Use **consistent indentation** (4 spaces recommended)
- Do **not** mix tabs and spaces

```c
if (value > 0)
{
    result = value * 2;
}
```

---

### 3.2 Braces

- Always use braces `{ }`, even for single statements

**Good:**
```c
if (flag)
{
    led_on();
}
```

**Bad:**
```c
if (flag)
    led_on();
```

---

## 4. Comments

### 4.1 Why Comments Matter

Comments explain **intent**, not obvious syntax.

---

### 4.2 File Header Comment

Each `.c` file should start with a short description:

```c
/*
 * File: main.c
 * Description: Simple calculator program
 */
```

---

### 4.3 Function Comments

Explain **what** the function does, not how every line works.
Below a template how it can look like including

* short and optionally more detailed description
* description of paramters
* description of return value

```c
/**
 * @brief short description of the function
 *
 * More detailed description if needed
 *
 * @param[in]  param1 Explain parameter 1 (Input)
 * @param[out] param2 Explain parameter 2 (Output/Pointer)
 * @return            Explanation of return value
 */
```

---

## 5. Variables and Initialization

### 5.1 Always Initialize Variables

Uninitialized variables cause **undefined behavior**.

**Good:**
```c
int counter = 0;
float voltage = 0.0f;
```

**Bad:**
```c
int counter;
```

---

### 5.2 One Variable per Line

Improves readability and debugging.

```c
int x;
int y;
int z;
```

---

## 6. Control Structures

### 6.1 if / else

- Conditions should be easy to read

```c
if (temperature > MAX_TEMP)
{
    alarm_on();
}
else
{
    alarm_off();
}
```

---

### 6.2 Loops

- Use clear loop bounds
- Avoid infinite loops unless intended

```c
for (int i = 0; i < 10; i++)
{
    process_value(i);
}
```

---

## 7. Magic Numbers

Avoid unnamed numbers in code.

**Bad:**
```c
if (value > 42)
```

**Good:**
```c
const int LIMIT = 42;

if (value > LIMIT)
```

---

## 8. Functions

### 8.1 Keep Functions Short

- One function = one task
- Ideal length: **< 30 lines**

---

### 8.2 Avoid Global Variables

- Prefer local variables
- Globals make programs harder to understand

---

## 9. Pointers (Basic Rules)

Pointers are powerful but error-prone. Use them **carefully and clearly**.

### 9.1 Pointer Naming Convention

- Pointer variables must start with **`p`**
- The name should still describe the content
- Write the * next to the name, not the datatype

**Good:**
```c
int *p_value;
char *p_name;
```

**Bad:**
```c
int* value;
char * ptr;
```

This makes pointer usage immediately visible when reading code.

---

### 9.2 Pointer Initialization

- Always initialize pointers
- Use `NULL` if no valid address is available

```c
int *p_data = NULL;
```

---

## 10. Casting

Casting changes the type of a value. It should be **rare and explicit**.

### 10.1 When Casting Is Acceptable

- Converting between numeric types when required
- Interfacing with library functions

```c
float average = (float)sum / count;
```

---

### 10.2 Avoid Unnecessary Casts

**Bad:**
```c
int value = (int)10;
```

**Good:**
```c
int value = 10;
```

---

### 10.3 Never Hide Problems with Casts

Casting must not be used to silence warnings or hide errors.

---

## 11. Do Not Use `goto`

- `goto` makes code hard to read and maintain
- Structured control flow is always preferred

**Do not write:**
```c
goto error;
```

Use `if`, `else`, `for`, `while`, and functions instead.

---

## 12. Error Handling (Basic)

- Always check return values when possible

```c
if (scanf("%d", &value) != 1)
{
    printf("Input error\n");
}
```

---

## 13. Modularization and Header Files

As programs grow, code must be **structured into modules**. Modularization improves readability, reuse, and maintainability.

---

### 13.1 What Is a Module?

A module typically consists of:
- one **source file** (`.c`)
- one **header file** (`.h`)

Each module should implement **one clear responsibility**.

Example:
- `calculator.c` – implementation
- `calculator.h` – interface

---

### 13.2 Header Files (`.h`)

Header files contain:
- function declarations
- type definitions (`struct`, `enum`)
- constants

Header files must **not** contain:
- function implementations
- global variable definitions

---

### 13.3 Include Guards

Every header file must use include guards to prevent multiple inclusion.

```c
#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);
int subtract(int a, int b);

#endif /* CALCULATOR_H */
```

---

### 13.4 Source Files (`.c`)

Source files:
- include their own header file
- contain the function implementations

```c
#include "calculator.h"

int add(int a, int b)
{
    return a + b;
}
```

---

### 13.5 Visibility: `static`

- Use `static` for functions and variables that are **only used inside one file**
- This prevents accidental usage from other modules

```c
static int helper_function(int value)
{
    return value * 2;
}
```

---

### 13.6 Why Modularization Matters

- Easier testing
- Easier debugging
- Clear separation of responsibilities
- Better teamwork

---

## 14. Final Advice

- Write code for **humans**, not for the compiler
- Be consistent
- If unsure: choose the **simpler** solution

> Clean code is a skill — it improves with practice.

---
