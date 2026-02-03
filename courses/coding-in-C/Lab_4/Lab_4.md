# Lab 4: Palindrome Detective

## Introduction
Write a C program that checks if a given word is a palindrome.  
A palindrome is a word that reads the same forwards and backwards (e.g., "level", "radar").

## Section I

Write a short program following these steps:
1. Creates a string with the content: "Curly bird catches the worm".
2. Create a pointer to this string.
3. Print out both contents. What did you notice? What two things do they both have in common?
4. Use the pointer and change the first two letters to 'E' and 'a'. What is this syntax called?
5. Write a function that takes a string as input.
6. The function should change the second letter of the string to 'c'.
7. Call the function with a string literal "AAtions speak louder than words" directly as parameter. What happens and why?
8. Resolve the issue from point 7.

## Section II

### Requirements

1. Prompt the user to enter a word (maximum 100 characters).
2. Read the input safely into a character array.
3. Check if the word is a palindrome (case-sensitive).
4. Print the result in the following format:

Your provided word "WORD" is a palindrome.

or

Your provided word "WORD" is not a palindrome.

5. You can use other libraries e.g. string operations.

### Example

Please enter your word (max. 100 characters): radar

Your provided word "radar" is a palindrome.

## Section III

Adapt your program from section II so that it is case-insensitive.
