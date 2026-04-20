# Lab 1: From C to C++

This lab focuses on getting started with C++ especially for programmers familiar with C.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Get running
The goal of this section is to run your first C++ project.

You will practice the following concepts:
* C++ compiler (g++) usage
* C++ file extensions

### Task Description

* **Requirement**: You forked the repository
* Open GitHub Codespace with the C++ project configuration
* Create a file called helloWorld.cpp
* Write an application that prints __Hello World!__ on the console
* Now open the "Run & Debug" view in VSCode and select the "Run/Debug C++" option before pressing the green Play-Button
* Note: If you do not see the option "Run/Debug C++", you might have an earlier version of this repo. Try to sync your fork.
* Ensure that the text is correctly printed out on the terminal
* Now navigate with the terminal into the folder where you stored your helloWorld.cpp
* Delete the previously created executeable file from the folder
* Execute the following command:
```bash
g++ helloWorld.cpp -o helloWorld
```
* Then run the newly created executable file with:
```shell
./helloWorld
```
* Create another __Hello World__ example and save it in a .c file
* Check if you can compile it with the C++ compiler as before
* Create a C++ header file (.hpp)
* Add a function prototype to the header called __void printFromHeader()__
* The logic of this function should be defined in __helloWorld.cpp__ 
* __printFromHeader()__ should output the text:
```shell
"Hello from .hpp"
```
* Call the function in __helloWorld.cpp__ and run it to ensure it works

### Hints
* Feel free to repeat this process on your local machine to ensure a correct setup there too
* If you struggle with these steps or wonder how to get running on your private, local machine, you can follow the lab1 of the C course which can be found [in this same repo](https://github.com/christian-braunagel/study-code/tree/main/courses/coding-in-C/Lab_1)

## 🟢 Section II: Our C++ coding convention
The goal of this section is to familiarize yourself with the C++ coding convention of this course.

### Task Description
* Navigate to the __coding-in-C++__ folder and open the __cpp_coding_conventions.md__
* Read the convention in detail at least up to point 18.)
* Write down any point that is unclear to you for later discussions

## 🟢 Section III: Age Validation

The goal of this section is to get to know some new features of the C++ language.

You will practice the following concepts:
* bools
* portable data types
* namespaces
* input/output via streams

### Task Description
Your task is to implement a software that receives the age of an user via keyboard and determines if the user is a kid/teenager, an adult or a senior citizen.

### Requirements

* Create a namespace called __validation__
* Inside of it, implement two functions:
```c
bool isAdult(___ age)
```
* The function should return:
   * true if age is 18 or older
   * false otherwise
```c
bool isSenior(___ age);
```
* The function should return:
   * true if age is 65 or older
   * false otherwise

* As data type for the parameters, you should use a portable type from \<cstdint>.
* Do not use the __using__ keyword.
* Output of the main program should look like this:
```c
Please enter your age: 77
You are 77 years old.
That means that you are a senior citizen.
```
```c
Please enter your age: 48
You are 48 years old.
That means that you are an adult.
```
```c
Please enter your age: 13
You are 13 years old.
That means that you are still a kid or teenager.
```
```c
Please enter your age: abcd
You did not enter a valid number. Please try again.
Please enter your age:
```
* Ensure that the user input is a number not some random text
* Ensure that the user input is not negative
* Ensure that the user input is not unrealistic high
* Ask the user to re-enter the input if it was not valid
* Use the portable data type __uint8_t__ in the main function to store entered age.

### Questions & further tasks
Note: Write the answers for the questions in the code as comments.
* What exactly is the problem when using __uint8_t__ for storing the entered age of the user?
* Fix the issue when using __uint8_t__ by using an integer for the user input and static casts for the parameters instead.
* Which other portable data types would make sense in this example?

## 🟡 Section IV: Student Grade Report Formatter

You will practice the following concepts:

* Call-by-reference (references)
* `std::string`
* Formatted output with `std::cout`
* I/O manipulators

### Task

Write a C++ program that reads information about a student, calculates the final grade, and prints a formatted report card.

Your program must be divided into **multiple functions**.

---

### Step 1 — Read Student Data

Create the following function:

```cpp
void readStudentData(__ name,
                     __ homework,
                     __ midterm,
                     __ finalExam);
```

The function should:

1. Ask the user for the **student name** and read it using getline
2. Ask for three scores:

   * Homework
   * Midterm
   * Final exam
3. Store all inputs using **call-by-reference parameters**
4. Ensure that the scores are in the range of [0, 100] and if not:
   * Reset error status
   * flush buffer
   * request another input
5. Use portable data types to ensure the most time efficient execution of the code

#### Example Input

```
Enter student name: Alice
Homework score: 87
Midterm score: 78
Final exam score: 92
```

---

### Step 2 — Calculate the Final Grade

Create the function:

```cpp
void calculateGrade(__ homework,
                    __ midterm,
                    __ finalExam,
                    __ finalGrade,
                    __ letterGrade);
```
that calculates the final grade based on the rules below:

### Grade Weights

| Component  | Weight |
| ---------- | ------ |
| Homework   | 40%    |
| Midterm    | 25%    |
| Final Exam | 35%    |

## Letter Grades

| Range | Grade |
| ----- | ----- |
| ≥ 90  | A     |
| ≥ 80  | B     |
| ≥ 70  | C     |
| ≥ 60  | D     |
| ≥ 50  | E     |
| < 50  | F     |

The parameter letter_grade must be of type __string__.

Return the results using **reference parameters**.

---

### Step 3 — Print a Formatted Report

Create the function:

```cpp
void printReport(__ name,
                 __ homework,
                 __ midterm,
                 __ finalExam,
                 __ finalGrade,
                 __ letterGrade);
```
that creates the formatted report card.

It also determines a status string based on the letter grade using __string comparison__:

```
Letter       	Status
-----------------------
A,B,C	        PASS
D,E	            CONDITIONAL PASS
F	            FAIL
```

The function __printReport__ should use manipulators to format the report card.

You should use at least:
```cpp
std::left and std::right
std::setw(n)
std::setprecision(n)
```
#### Example Output

```
-------------------------------------
Student Report
-------------------------------------
Name: Alice

Scores
-------------------------------------
Homework        : 87.00
Midterm         : 78.00
Final Exam      : 92.00

Final Grade     : 86.05
Letter Grade    : B
Status          : Pass
-------------------------------------
```

---

### Step 4 — Other requirements

Your `main()` should:

1. Declare all required variables
2. Call the functions in the correct order
3. Print the final report

The program should be implemented in a modular way using header files.
