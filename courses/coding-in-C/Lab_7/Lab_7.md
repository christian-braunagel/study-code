# Lab 7: Playlist Manager

## Section I

### Exercise Goals:
- How to use dynamic memory allocation with malloc()
- How to resize allocated memory
- How to free up allocated memory space

### Requirements:

1. Create a program that asks the user for a integer __N__ and then uses malloc() to reserve enough memory for this variable and save __N__ at this address.
2. Now use the function calloc() to reserve memory for __N__ integer variables (e.g. if __N__= 3 reserve memory for 3 integers).
3. Fill the created array of step2 with the square numbers of their index e.g. arr[i] = i*i
4. Afterwards, resize the array so it is twice as big (2 x __N__) and fill in the square numbers for the new indices.
5. Print the array.
6. Finally release the memory completely and end the program.
7. Comment into the code what the two main differences between calloc and malloc are.

## Section II

### Exercise Goals:
- Understand how linked lists are implemented in C

1. Create a struct type called Node (using typedef) that represents a Node of a linked list which can store a double value.
2. Define a starting pointer for the linked list called head.
3. Write a function that creates and returns new nodes of the linked list including a double value handed over as parameter to the function.
4. Create 50 nodes and add them all to the linked list starting with the pointer head.
5. Create an array with 51 elements.
6. The array should be filled with 50 random integer numbers from index 0 to 49.
7. Now create an additional random number and
   - insert it at index 3 of the array
   - insert a new node into the linked list as 3rd node.
   - Please shift for both options all the remaining nodes or array elements after the newly inserted value by one step.
8. Print the array and the list.
9. What would you say is the more time-consuming way to insert a new value: when using an array or when using a linked list? Comment in the code.
10. At the end, do not forget to free up your allocated memory.

## Section III
In this lab exercise, you will implement a simple music playlist manager using the C programming language.  
The goal of this assignment is to practice working with:

- `struct` data types
- pointers
- dynamic memory allocation (`malloc`, `free`)
- singly linked lists

The playlist is implemented as a linked list where each element represents a song consisting of a title and an artist.

## Requirements

Your program must fulfill the following requirements:

### Data Structures

1. Define a structure `Song` that contains:
   - a dynamically allocated string for the song title
   - a dynamically allocated string for the artist name
   - a pointer to the next song in the playlist

2. Define a structure `Playlist` that contains:
   - a pointer to the first song in the playlist

---

### Functions

Implement at least the following functions:

- `init_playlist`  
  Initializes an empty playlist.

- `add_song`  
  Adds a new song to the end of the playlist.  
  Memory for the song structure and its strings must be allocated dynamically.

- `print_playlist`  
  Prints all songs in the playlist in the following format:
  
  Title: __title__, Artist: __artist__

- `delete_firstSong`  
Removes the first song from the playlist and frees all allocated memory.

- `delete_playlist`  
Removes all songs from the playlist and frees all allocated memory.

---

### Main Program

In the `main` function, demonstrate the functionality of your program by:

1. Creating and initializing a playlist
2. Adding multiple songs to the playlist
3. Printing the playlist
4. Deleting the first song
5. Printing the playlist again
6. Deleting the complete playlist

## Example

Title: Crawling, Artist: Linkin Park
Title: Layla, Artist: Eric Clapton
Title: Esperanto, Artist: Max Herre

## Hints

- Use only standard C libraries:
  - `<stdio.h>`
  - `<stdlib.h>`
  - `<string.h>`
- Always free dynamically allocated memory to avoid memory leaks
- Check the return value of `malloc` before using allocated memory
- Keep your code modular by separating functionality into functions
- Use meaningful variable and function names
- Optional extensions:
  - delete a song by title
  - count the number of songs in the playlist
  - insert a song at a specific position in the playlist

