# Lab 3: Relations between Classes

This lab introduces fundamental concepts of object-oriented programming in C++, with a focus on modeling and implementing relationships between classes.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟡 Section I: UML Modeling – Online Learning Platform

In this section you will model a simplified **Online Learning Platform** and focus on identifying and designing **relationships** between classes.

You will practice the following concepts:

- UML class diagrams
- identifying **composition vs aggregation**  
- modeling multiplicities and associations  
- transferring UML into C++ code  

---

### 🧩 Task Description

You are asked to design a simplified **Online Learning Platform** (similar to Moodle).

The platform manages courses, learning content, and users.

---

### 📘 Requirements

- The platform offers multiple **courses**.
   - The number of courses is technically limited to **100**

- A **course** represents a learning unit:
  - it should have a title and a description  
  - it should allow adding or in general organizing its learning material 

- A course is structured into smaller parts called **lessons**:
  - each lesson can contain different types of **content**  
  - content could be, for example, text, video, or quizzes  

- Users can participate in courses:
  - a **user** should have identifying information  
  - users should be able to enroll or leave in courses  
  - users need to be registered **at least on one platform** (e.g. Moodle RV, FN, etc.) 

---

### Task Part 1 – UML Diagram

Create a UML class diagram in draw.io that:

1. Identifies all relevant classes based on the description  
2. Defines:
   - attributes with visibility and types  
   - methods (at least one meaningful method per class)

3. Models relationships:
   - clearly distinguish between:
     - **composition**
     - **aggregation**
     - **association**

4. Includes:
   - multiplicities (e.g. 1, 0..*, etc.)
   - roles or attributes connecting the classes

You must decide yourself:
- which elements should be modeled as **classes**
- which properties should be **attributes**
- which actions should be **methods**

and especially:

- which relationships are **compositions**
- which are **aggregations**
- which are simple **associations**

---

### Task Part 2 – Justification

Answer the following:

1. Which relationships did you model as **composition** and why?  
2. Which relationships did you model as **aggregation** and why?  
3. Which design decisions were not obvious and could be modeled differently?  

👉 There is not always a single correct answer — your reasoning is essential.

---

### Task Part 3 – C++ Implementation

Transfer your UML model into C++ code.

---

- Implement the classes you identified  
- Use appropriate access modifiers (`private`, `public`)  
- Represent relationships using:
  - direct members (for strong ownership)
  - pointers or references (for weaker relationships)

- In main, create objects of your classes
- Simulate interaction (e.g. enrolling, accessing content)  
- Call at least one method from each class  

## 🟢 Section II: Inheritance in C++ – Basics and Practice

In this section you will explore inheritance as a fundamental mechanism to model relationships between classes and reuse code.

You will practice the following concepts:

basic inheritance syntax in C++
access modifiers (public, protected, private)
using protected members
constructors in base and derived classes
passing parameters to base class constructors

---

### 🧩 Task Description

You will extend a simple class hierarchy to model different types of users in a learning platform.

### 📘 Requirements

Start with a base class **User**.

Use the following UML class diagram:

![User UML](lab3_sectionII.svg)

The diagram specifies:
- attributes (including visibility)
- constructor
- member functions

---

### 🟢 Task Part 1 – UML Interpretation

- Interpret the UML diagram of the `User` class  
- Identify:
  - attributes and their visibility  
  - constructor parameters  
  - available methods
- Transfer it into C++ code

---

### 🟢 Task Part 2 – Basic Inheritance

- Create two derived classes:

  - `Student`
  - `Instructor`

- Both classes should:

  - inherit from `User`
  - have at least one additional attribute  
  - implement a method `printRole()` that uses the inherited attributes from `User` in the derived classes

- Add a short comment explaining:
  - why `protected` is used instead of `private`
- Implement constructors for `Student` and `Instructor`  
- Use initializer lists to call the base class constructor  

To test the classes in main:
- Create objects of:
  - `Student`
  - `Instructor`  

- Call:
  - `printInfo()`  
  - `printRole()`  

### 💬 Reflection Questions

1. What would change if the access specifier in the inheritance declaration is deleted?

2. Why is it important to call the base class constructor?

---

## 🟡 Section III: UML Review – Library Management System

In this section you will analyze an existing UML class diagram and evaluate whether the object-oriented design is reasonable.

Unlike previous tasks, you are **not creating a design from scratch**, but reviewing and improving an existing one.

---

### 🎯 Learning Goals

In this task you will practice:

- analyzing UML class diagrams
- evaluating class relationships
- identifying composition, aggregation, association, and inheritance
- checking visibility and encapsulation
- reasoning about object-oriented design decisions

---

### 📘 Scenario

A library manages different types of books.  
Members can borrow books, and librarians can register members.  
Whenever a member borrows a book, a loan record is created.

The system contains the following classes:

- `Library`
- `Book`
- `PrintedBook`
- `EBook`
- `Member`
- `Librarian`
- `Loan`

Use the provided UML class diagram:

![Library UML](sectionIII_library_uml_review.svg)

---

### Task Part 1 – Understand the Diagram

Analyze the UML diagram and answer:

1. Which classes are modeled?
2. Which attributes and methods are visible from outside the class?
3. Which inheritance relationships are shown?
4. Which composition, aggregation, or association relationships are shown?

---

### Task Part 2 – Evaluate the Design

Decide which parts of the diagram represent good object-oriented design and which should be improved.

Answer the following:

1. Which relationships are modeled correctly? Explain why.
2. Which relationships are questionable or incorrect? Explain why.
3. Is inheritance used appropriately in all cases?
4. Does the design preserve encapsulation?

---

### Task Part 3 – Improve the Diagram

Create an improved UML class diagram.

Your improved diagram should:

- fix incorrect relationships
- improve visibility where necessary
- preserve meaningful inheritance
- use composition, aggregation, and association appropriately
- briefly justify your changes if not yet done in Part 2

---

## 🔴 Section IV: Game Character System – Inheritance and Class Relationships

You are part of a small game development studio working on a new fantasy role-playing game.  
Your team is responsible for implementing the first version of the character system.

The game should support different types of characters, such as warriors and mages.  
Each character owns an inventory and can use a weapon. Your task is to model the system using UML and then implement it in C++.

---

### 🎯 Learning Goals

In this task you will practice:

- modeling inheritance in UML
- identifying class relationships
- distinguishing composition, aggregation, and association
- implementing inheritance in C++
- understanding controlled access between classes using friend

---

### 📘 Requirements

The game contains different characters.

Each character has:

- a name
- health points (must be `private`)
- a level

There are two main character types:

- `Warrior`
- `Mage`

A `Warrior` has:

- weapon skill points

A `Mage` has:

- mana points

Both types can regenerate their specific points and have a method to display their status including:
- name
- their type
- health points
- magic points or weapon skill points
- level
- current weapon
- number of items in inventory compared to maximum slot number (e.g. 4/10)

The minimum level is 1 while the maximum level is 10.
To reach the next level, a level specific experience point limit has to be surpassed.
In that case, the method levelUp() should be called.

Each character owns exactly one `Inventory`.

To allow controlled inventory access, `Character` should provide a method such as:

    Inventory& getInventory();

An `Inventory` can store a limited number of item names.

A character can use one `Weapon`.

A `Weapon` has:

- a name
- a damage value

In addition, there are jobs with specific skills which are based on exactly one of these two character types such as:
- Thief (can steal from enemies)
- Healer (can heal other characters and himself)

Every job skill should return the calling object so that multiple skills can be called fluently in sequence.

---

🧙 Additional Role: Healer

A Healer is a special class derived from Mage.

The Healer can:

- heal other characters
- heal itself

👉 Important constraint:

- The attribute health points in Character must remain private
- No public setter for health points is allowed
- Other classes must not be able to modify health directly
- Use ```friend``` to access the health points

⚙️ Healing Behavior
Implement a method:
```c++
Healer& heal(Character& target);
```
The method increases the health points of the target

---

### 🗡️ Additional Role: Thief

A `Thief` is a special class derived from `Warrior`.

The `Thief` can:

- steal items from other characters  
- add stolen items to its own inventory  
- fail if the target has no items  
- fail if the thief’s inventory is full  

---

### ⚙️ Stealing Behavior

Implement a method:

    Thief& steal(Character& target);

The method tries to transfer **one item** from the target’s inventory to the thief’s inventory.

A possible rule:

- stealing succeeds if the thief is strong enough (e.g. based on weapon skill points and target level)

If stealing succeeds:

- remove one item from the target’s inventory  
- add that item to the thief’s inventory  

If stealing fails:

- both inventories remain unchanged  

The method should return the calling object to allow method chaining.

---

### 🧩 Design Constraint

- The `Thief` must **not** access the target’s inventory directly  
- All interactions with an inventory must happen through its **public methods**  

---

### 📦 Required Inventory Interface

To support stealing, the `Inventory` should provide controlled methods such as:

    bool isEmpty() const;
    bool isFull() const;
    bool addItem(const std::string& item);
    bool removeLastItem(std::string& item);

---

### 🟡 Task Part 1 – UML Class Diagram

Create a UML class diagram based on the requirements above.

Your UML diagram must include:

- attributes with visibility and data types
- methods with visibility and return types
- inheritance relationships
- composition, aggregation, or association where appropriate
- multiplicities
- at least one static attribute
- marked readonly attributes, methods and/or parameters (use direction for that)

Explain why you selected the relation types you used between the created classes (e.g. in a text area within your diagram).

---

### 🟡 Task Part 2 – Implementation

Implement the designed UML architecture and write the logic based on the requirements.

Answer the following questions:
- Why is friend used instead of a public setter for health points? What is the benefit?
- What would happen if multiple classes were declared as ```friend```?
- Why is stealing implemented through public `Inventory` methods instead of direct access to private inventory data?
- Compare the two options: using a ```friend class``` vs ```public interfaces```

---

### 🟡 Task Part 3 – Main

Test your program in a main function:
- Create 3-4 characters of different types
- Call the various methods to ensure correct behavior of your program
- Use method chaining where possible

Special task:
- Add all characters into one array
- Print out the current character level of each array element

