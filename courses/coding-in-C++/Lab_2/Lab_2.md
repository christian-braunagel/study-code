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
* `getAccountInfo()` should return owner and balance
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

## 🟢 Section III: Note Class

