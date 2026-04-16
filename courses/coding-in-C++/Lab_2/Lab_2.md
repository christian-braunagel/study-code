# Lab 2: From C to C++

This lab focuses on getting started with C++ especially for programmers familiar with C.

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

## 🟡 Section III: Fault Analysis – Online Shop Article Class

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

### Hint
Many of the errors are related to core OOP principles such as encapsulation, proper initialization, and safe memory handling discussed in the lecture.

## 🟢 Section IV: Create UML Class Diagrams

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

---

## Tasks

1. Model the described system in an UML class diagram in drawIO.

2. For each class:
   - Define **attributes with visibility and data types**
   - Include at least:
     - one **static attribute**
     - one **derived attribute**

3. Define fitting **methods (operations)**:
   - At least per class:
     - one method **with parameters**
     - one method **without parameters**
   - Mark appropriate methods with `{query}`
   - Use the direction for parameters
