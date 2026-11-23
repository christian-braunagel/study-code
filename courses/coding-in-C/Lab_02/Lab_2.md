# Lab 2: Chessboard

## Introduction
Write a C program that prints the coordinates of a chessboard to the terminal.

## Section I

### Task Description

A standard chessboard consists of:
- 8 columns labelled `A` to `H`
- 8 rows labelled `1` to `8`

Your task is to write a C program that prints all chessboard fields in the following format:

A8 B8 C8 D8 E8 F8 G8 H8 

A7 B7 C7 D7 E7 F7 G7 H7

A6 B6 C6 D6 E6 F6 G6 H6

A5 B5 C5 D5 E5 F5 G5 H5

A4 B4 C4 D4 E4 F4 G4 H4

A3 B3 C3 D3 E3 F3 G3 H3

A2 B2 C2 D2 E2 F2 G2 H2

A1 B1 C1 D1 E1 F1 G1 H1

### Requirements

Your program must:

- print rows from `8` down to `1`
- print columns from `A` to `H`
- not hard-code each field manually

## Section II

Create a flow chart for the programm developed in Section I.
You can use [draw.io](https://www.drawio.com/) as a free tool to create the flow chart.

## Section III: Chessboard with Border and Alternating Fields

### Task Description

Extend the program from **Section I** so that the chessboard is printed as a **graphical board with borders**, labels, and a **correctly alternating field pattern**, similar to a real chessboard.

Instead of printing only the coordinates, your program shall visualize the board using ASCII characters.

The output must include:

- a surrounding grid made of `+`, `-`, and `|`
- file labels (`A` to `H`) printed **above and below** the board
- rank labels (`8` to `1`) printed **on the left and right** of each row
- a visual representation of the fields using characters (e.g. `###` for dark squares and spaces for light squares)
- a **checkerboard pattern**, where field colors alternate:
  - horizontally within a row
  - vertically from one row to the next

A schematic example of the intended structure:

![Image of final output for Section III](https://github.com/christian-braunagel/study-code/blob/main/courses/coding-in-C/Lab_2/schematicOutput.png)


(The exact characters and spacing must match your implementation.)

### Requirements

Your program must:

- not hard-code any rows, columns, or fields
- print rank numbers on **both the left and right side** of the board
- print file letters **above and below** the board
- visually distinguish light and dark squares
- ensure that the field pattern alternates correctly
- use constants (e.g. board size) where appropriate

The purpose of this task is to practice:

- nested loop logic
- conditional statements
- formatted output with `printf`
- translating a conceptual model (chessboard) into structured program output

### Hint (Optional)

Think about how the **row index and column index together** can be used to decide whether a field is light or dark.

