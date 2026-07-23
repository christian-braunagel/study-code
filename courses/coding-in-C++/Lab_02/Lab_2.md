# Lab 2: Basics of OOP

This lab focuses on the basics of object-oriented programming in C++ including UML class and object diagrams.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Bank Account Class
In this section you will develop your first class

You will practice the following concepts:
* Access modifiers
* class keyword
* attributes and methods

### Task Description

Implement a simple class “BankAccount” for account management that includes:

#### __Private__
* `std::string owner`
* `double balance`

#### __Public__
* `setOwner(...)`
* `getOwner(...)`
* `deposit(double)`
* `withdraw(double)`
* `getBalance()`
* `getAccountInfo()`

The following requirements should be met:
* deposits should be > 0
* withdrawals should only be possible if there is enough money in the account
* `getBalance()` and `getAccountInfo()` should be defined outside of the class
* `getAccountInfo()` should print owner and balance
* Check the class and its methods within the main function of your program

#### Question to answer
What problem do you see with respect to the attribute "balance" at the beginning of your program and how should this be solved? Write the answer into your code as comment.

## 🟢 Section II: Note Class

In this section you will work with dynamic memory and object lifetime.

You will practice the following concepts:
* dynamic memory allocation (`new` / `delete`)
* constructors and destructors
* pointers

### Task Description

Create a class “Note” that stores a text message which is only known at runtime.

#### __Private__
* `std::string* text`

#### __Public__
* `Note(std::string)`
* `~Note()`
* `display()`

### Requirements

* The constructor:
  - takes a `std::string` as input  
  - allocates memory dynamically  
  - copies the text into the allocated memory  

* The destructor:
  - frees the allocated memory
  - handles the dangling pointer
  - prints a short message: `"Memory released"`  

* `display()`:
  - prints the stored text to the console  

### Task Part 1

* Create an object of the class in the `main` function
* Create a second object and initialize it with the first object
* Call `display()` for both objects  
* Observe and explain in the comments:
   * Why can you initialize the second object with the first one?
   * When the destructor is automatically called
   * What exception occurs or might occur in the destructor

### Task Part 2

* Extend the class Note by implementing a copy constructor
* When a Note object is copied, the new object must allocate its own memory and store its own copy of the string
* Verify if this resolves the observed issue from Part 1

## 🟢 Section III: Our C++ coding convention Part 2
The goal of this section is to familiarize yourself with the C++ coding convention of this course.

### Task Description
* Navigate to the __coding-in-C++__ folder and open the __cpp_coding_conventions.md__
* Read the remaining points (starting with section 19) of the convention in detail
* Write down any point that is unclear to you for later discussions

## 🟢 Section IV: Fluent Drink Builder

In this task you will implement a small helper class using **method chaining** and **constexpr values**.

---

### 📘 Task Description

Implement a class `DrinkBuilder` that allows configuring a drink step by step using a fluent interface.

The goal is to enable code like this:

```cpp
DrinkBuilder builder;
builder.setName("Tea")
       .setSugar(2)
       .setTemperature(65)
       .setWithMilk(true)
       .print();
```

---

### Requirements

- The class should contain at least:
  - `std::string name`
  - `int sugar`
  - `int temperature`
  - `bool withMilk`

- Define at least one constant default value using `constexpr`, for example:
  - a default temperature
  - a maximum allowed sugar amount

- This constant must be available at compile time
- Use the `constexpr` value to initialize at least one attribute

- The class should have at least the following methods:
  - `setName(const std::string& name)`
  - `setSugar(int sugar)`
  - `setTemperature(int temperature)`
  - `setWithMilk(bool withMilk)`

Method chaining should be enabled.  
This means that all setter methods must:

- modify the object state
- return a reference to the current object (`*this`)

---

### Additional Methods

#### print()

- Outputs all current values in a readable format

#### isValid()

- Checks whether the current drink configuration is valid
- This method must be marked as `const`

---

### Additional Constraints

- Use `const std::string&` where appropriate
- At least one method must be marked as `const`
- Prevent invalid values, for example:
  - sugar must not be negative
  - temperature must be greater than 0
- Use reasonable default values with `constexpr`

---

### Example Output

```text
Drink: Tea
Sugar: 2
Temperature: 65
With milk: true
```

---

## 🟡 Section V: Fault Analysis – Online Shop Article Class

In this section you will analyze and debug an existing class implementation instead of writing one from scratch.

You will practice the following concepts:

* access modifiers (public / private)
* constructors and initialization
* the this pointer
* const-correctness
* dynamic memory management (new / delete)

### Task Description

The following class Article is intended to represent a product in an online shop.
However, the implementation contains multiple conceptual, stylistic and technical errors.

```c++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Article {
public:
    string name;
    double price;
    int stock;
    string* category;
    int id;

    Article(string name, double price, int stock, string category, int id) {
        name = name;
        price = price;
        stock = stock;
        this->id = id;
        this->category = new string;
        *this->category = category;
    }

    void setPrice(double price) {
        price = price;
    }

    void sell(int amount) {
        stock = stock - amount;
    }

    void restock(int amount) {
        this->stock += amount;
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() {
        return price;
    }

    bool isAvailable() {
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.price = -100;
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}
```

### Task Part 1
Find at least 14 issues in the code.

For each issue:
* describe what the problem is
* explain why it is problematic
* suggest how it should be fixed

### Task Part 2

Answer the following questions:

1. Why is the use of new for the category attribute problematic in this case?
2. What could happen if multiple objects of this class are copied?
3. Why should some methods be marked as const?
4. What risks arise from allowing direct access to price and stock?

### Task Part 3
Write a corrected version of the program that solves all found issues and is in accordance with our coding convention.

### Task Part 4
Based on your developed code, create two UML diagrams: one class and one object diagram.

The **class diagram** should contain all the details possible which are also available in the code including:
- attributes
- methods
- visibility
- data types
- parameter with direction
- special behaviour such as static or derived attributes

The **UML object diagram** shows one concrete snapshot of your system at runtime.
Please use meaningful object names and concrete attribute values.

### Hint
Many of the errors are related to core OOP principles such as encapsulation, proper initialization, and safe memory handling discussed in the lecture.

## 🟢 Section VI: Create UML Class Diagram

In this section you will practice the basics of the UML class diagram notation.

### Task Description

You are asked to model a small system for a **cinema**.

A cinema manages movies, customers, and tickets.

- A **Movie** has a title, duration (in minutes), and a base price.
- A **Customer** has a name and a unique customer ID.
- A **Ticket** represents the purchase of a movie ticket and contains the movie price.

### Requirements

- A movie can calculate its **price with tax**.
- A ticket stores the **seat number** and whether it has been used.
- A ticket can be **validated** (used).
- A customer can check whether they are a **VIP customer** (based on internal/hidden logic).
- The total number of created tickets should be tracked.
- The final ticket price depends on the movie price.


### Tasks

1. Model the described system in an UML class diagram in drawIO.

2. For each class:
   - Define **attributes with visibility and data types**
   - Include at least:
     - one **static attribute** or
     - one **derived attribute**

3. Define fitting **methods (operations)**:
   - At least per class:
     - one method **with parameters**
     - one method **without parameters**
   - Mark appropriate methods with `{query}`
   - Use the direction for parameters

## 🔴 Section VII: Search Engine

In this section, you will create a simplified **Search Engine System** including UML diagrams and C++ code.

---

### 📘 System Description

A search engine allows users to enter a textual query in order to find relevant web content.

Each searchable item in the system represents a web resource.  
Such a resource has a unique address, contains textual information, and has an internal ranking value that indicates how relevant or important it is.  
Some values are not stored directly but can be derived, for example whether a resource is considered “popular” based on its ranking.

Users interact with the system by entering search queries.  
A query consists of a text input and may define a maximum number of results that should be returned.  
It should be possible to check whether a query is valid (e.g. not empty).

The system itself processes queries and keeps track of usage statistics.  
For example, it may count how many queries have been executed in total.  
Additionally, the system should be able to output basic information about itself.

Each component of the system should provide meaningful functionality, such as:

- displaying its internal state in a readable format  
- checking conditions without modifying internal data  
- processing input parameters where appropriate

---

### Tasks: Part I

- Create an **UML class diagram** for the described system
- You must **identify all necessary classes yourself**  
- Decide which elements are:
  - **attributes**
  - **methods (operations)**  
- Include:
  - visibility (`+`, `-`)  
  - data types  
  - return types  
  - parameters including direction
  - mark readonly methods as `{query}`  

- Your diagram must contain at least:
  - one **static attribute**  
  - one **derived attribute**  

🚫 Do **not** model relationships between classes in this task.

- Create an **UML object diagram** that shows one concrete snapshot of your system at runtime
- Use meaningful object names and concrete attribute values

### Tasks: Part II

- Based on your UML diagram, implement the Search Engine system in C++
- The code should reflect exactly your UML architecture
- The code should consider OOP best-practices such as abstraction and encapsulation

Additionally, implement the following functionality:
- Implement one or more methods that perform the actual search feature; e.g.
   - storing several web resources inside the search engine
   - checking whether the query text is contained in the text content of a resource
   - sorting all matching resources by ranking in descending order
   - returning or printing only the first `maxResults` matches

- Demonstrate the functionality in `main()` with multiple resources and at least two different queries
