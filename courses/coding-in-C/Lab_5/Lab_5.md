# Lab 5: Random Particle Simulation with Pointers

## Section I
Given the following code:
```c
#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", ???);
    printf("x via p = %d\n", ???);
    printf("x via pp = %d\n", ???);

    return 0;
}
```
### Tasks:
1. Replace the ??? so that the value of x is printed:
   - directly
   - via the pointer p
   - via the pointer-to-pointer pp
2. Then change the value of x via pp to 42.
3. Print x again and verify the result.
4. What are the types of the following expressions?
- x
- p
- *p
- pp
- *pp
- **pp

## Section II

Write a C program that:

1. Uses the following main signature:
```c
int main(int argc, char **argv)
```
2. Expects at least one command-line argument (excluding the program name).
3. Iterates over all provided arguments by using
   - array indexing with [ ]

   and in a second variant by using
   - pointer dereferencing
4. Prints for each argument:
   - its index
   - its address
   - the content
   - its length (number of characters, excluding the null terminator)
5. Explain the relation between indexing (using []) and pointer dereferencing.
6. Explain the relation between arrays and pointers.


### Example Usage and Output:
```bash
$ ./args hello world
Argument 0 at address "000001A174C03D00" has content: C:\Users\Braunagel\Projects\Lab_5\solution\args.exe (length: 51)
Argument 1 at address "000001A174BFD990" has content: hello (length: 5)
Argument 2 at address "000001A174BFAE00" has content: world (length: 5)
```

### Constraints
- Do not modify the contents of argv
- Do not use global variables
- Use standard C library functions only

## Section III

### Introduction
In this exercise, you will simulate a simple 1D particle system using pointers in C.  
Each particle can move randomly either left or right at each discrete time step.  
You will practice:

- Using pointers to manipulate arrays
- Pointer dereferencing and pointer arithmetic
- Handling collisions
- Implementing a discrete-time simulation

### Requirements

1. Create an integer array initialized with zeros.
2. Place **three particles** at positions 2, 4, and 6 (set array values to 1 at these indices).
Note: If you place the particles with an odd distance, the will never collide.
3. Create a pointer pointing to the first element of the array.
4. Create a **temporary array** and a pointer to it to help you create and store the next state of the simulation.
5. Simulate in **discrete time steps**. For each step:
   - Print the current field (1 for particle, 0 for empty).
   - Move each particle randomly to the left or right by one cell.
   - Ensure particles **do not move out of bounds** but stay at the edge of the field.
   - If multiple particles move into the same cell, remove them (set cell to 0). This is called a collision.
6. Do **not** use structs
7. Use `<stdlib.h>` and `<time.h>` for random number generation.

### Example

Time 0: 0 0 1 0 1 0 1 0 0 0 

Time 1: 0 1 0 0 0 1 0 1 0 0

Collision on index 6

Time 2: 0 0 1 0 0 0 0 0 0 0

Time 3: 0 1 0 0 0 0 0 0 0 0


### Hints

- Use pointer dereferencing: `*(p_field + i)` to access elements.
- Use pointer arithmetic for both reading and writing.
- Generate random movement with `rand()`.
- Handle collisions after all movements are applied.

