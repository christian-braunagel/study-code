# Lab 3: Simple Calculator

## Introduction
Implement a simple command-line calculator in C that performs basic arithmetic operations on two numbers.

## Section I

### Task Description

Write a C program that:

1. asks the user to input two floating-point numbers
2. reads the numbers from standard input
3. asks the user to choose an arithmetic operation
4. performs the selected calculation
5. prints the result to the terminal

The supported operations are:

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

### Requirements

Your program should:

1. Prompt the user for the first number
2. Prompt the user for the second number
3. Prompt the user for the desired operation
4. Handle invalid operations gracefully
5. Prevent division by zero
6. Compute the result based on the selected operation
7. Use if-statements to determine the selected operation
8. Output the result in a readable format

Example output:
The result of 3.00 + 4.00 = 7.00

## Section II

Adapt the program of Section I by swapping the if-statements with a switch-case block.

## Section III

Adapt the program of the previous section by moving each arithmetical operation to a separate function.
These functions are then called if the user selects the corresponding operation.
