# Lab 12: Read, Write, Assert

## Section I:
Create a program that performs the following steps:

* Write a function copy_first_line() that reads the first line from a source file and writes it into a target file.
* Critical errors in this program (e.g., failed file opening) should be handled using assert().
* In main(), first open a new file and write two arbitrary lines of text to it.
* Then, call the copy_first_line() function.
* Afterward, use assert to verify whether the copying of the first line was successful.