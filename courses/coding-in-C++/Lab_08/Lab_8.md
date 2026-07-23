# Lab 8: Design guidelines and patterns


All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: SOLID BugHunt - FootballManager

In this section, you will analyze a small C++ project called `FootballManager`.

The project compiles and runs, but its design is intentionally poor.  
Your task is to find design problems related to the **SOLID principles** and refactor the code.

The SOLID principles are:

- **S**ingle Responsibility Principle
- **O**pen/Closed Principle
- **L**iskov Substitution Principle
- **I**nterface Segregation Principle
- **D**ependency Inversion Principle

---

## Task Description

Analyze the given project files:

- `FootballManager.hpp`
- `FootballManager.cpp`

The current implementation violates all five SOLID principles at least once.

Your tasks:

1. Identify at least **one violation for each SOLID principle**.
2. Write your findings as comments in the code or in a separate markdown file.
3. Refactor the project so that the SOLID principles are considered.
4. The program should still be able to:
   - manage a football player
   - train a player
   - select a match strategy
   - save player data
   - send a message to the player
   - print a sponsor report

Answer as comments in the code:

- Which class violates the Single Responsibility Principle?
- Where is the Open/Closed Principle violated?
- Where is the Interface Segregation Principle violated?
- Why is `InjuredPlayer` problematic regarding the Liskov Substitution Principle?
- Which concrete dependencies should be replaced by abstractions?
