# Lab 10: Smart Pointers

In this lab, you practice using smart pointers in C++. You will learn how to use `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr` to manage dynamic memory safely and efficiently.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: Library Catalog Ownership

Your task is to build a tiny library catalog.

The ownership rules are:

* A physical book copy can only be owned by one part of the program at a time. Therefore, it is stored in a `std::unique_ptr<Book>`.
* Author information can be reused by several books. Therefore, each book stores a `std::shared_ptr<Author>`.

---

### Step 1: Create the Author Class and Book Class

Create a class called `Author`. Every author object is created with a name and an id.
The class has setter and getter methods for all attributes.

Next, create a class called `Book` including a title and a shared pointer to an author.
Moreover, the class has:

* a constructor that receives the title and the shared author
* a method `printInfo()` that prints the title and the author name
* a destructor that prints when the book object is destroyed
* all getter and setter methods

Note: Use std::move to transfer ownership of the shared pointer within the constructor and the getter and setter methods, because it is more efficient than copying the shared pointer.

---

### Step 2: Use `std::shared_ptr` for Shared Author Data

In `main`, create one author and two different books that use the same author object.

Print the author's reference count with:

```cpp
use_count()
```

---

### Step 3: Use `std::unique_ptr` for Book Ownership

Now create two example books using unique pointers.

Then write a function called `lendBook` that receives a book by `std::unique_ptr` as a parameter and prints its information.

The function represents a library action that takes one physical book copy out of the catalog and lends it to a "borrower". Because the function receives a `std::unique_ptr<Book>`, the caller must transfer ownership to the function.

Call the function from `main` for both created example books.

After each function call:

1. Check that the original catalog pointer is now empty.
2. Print a short message if the book is no longer available in the catalog.

Check if the program correctly calls the destructor of the `Book` class when the unique pointer goes out of scope.

Check if the program correctly calls the destructor of the `Author` class when the last shared pointer to the author goes out of scope.

