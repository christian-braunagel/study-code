# Lab 9: Professional Playlist Manager

## Introduction
In this lab, you will extend the existing **modular Playlist Manager** application.
The goal is to practice **search algorithms**, **sorting algorithms**, and **recursion**
using a real data structure (a linked list).

You will work exclusively on the existing playlist implementation and add new
algorithmic functionality without changing the basic data structures.

The project already provides:
- a `Playlist` structure containing a linked list of `Song` elements
- functions to add, delete, and print songs
- a modular project structure using header and source files

## Section I: Search Algorithms

In this section, you should implement a linear search algorithm.
That means that your search algorithm simply moves through your list and checks every element. If the correct element is found, the algorithm stops.

### Requirements

1. Implement a function that searches for a song by its title.

2.  **Function prototype:**
```c
Song* find_song_by_title(Playlist *playlist, const char *title);
    
```
3. Use a linear search and strcmp for string comparison.

4. Return a pointer to the found Song.

5. Return NULL if the song is not found.


## Section II: Counting Songs

### Requirements

1. Implement a recursive function that counts the number of songs in the playlist.

```c
int count_songs_recursive(const Song *current);
```
2. No loops (for, while) are used
3. Use recursion only

## Section III: Sorting Algorithms

### Requirements

1. Implement a function that sorts the playlist alphabetically by song title.

```c
void sort_playlist_by_title(Playlist *playlist);
```
2. Use the Selection, Insertion or Quicksort.
3. You may swap song contents instead of list nodes but this is not mandatory.

## Section IV: Adapt main.c to show-case the new functions

### Requirements

1. Initialize a new `Playlist` using `init_playlist`.
2. Add at least four songs to the playlist using `add_song`.
3. Print the playlist using `print_playlist`.
4. **Search functions:**
   - Use `find_song_by_title` to find a song by its title (iterative)
   - Print the results to the console
5. **Recursion function:**
   - Use `count_songs_recursive` to count the number of songs
   - Print the count to the console
6. **Sorting function:**
   - Use `sort_playlist_by_title` to sort the playlist alphabetically
   - Print the playlist after sorting
7. Delete the entire playlist using `delete_playlist` to free memory.
8. Each function should be called in a **separate block** (e.g. highlighted by comments)

## General Hints

* Work directly on the linked list structure
* Recursion works naturally on linked lists
* Keep your code modular and readable
* Test each function individually before combining them
* Use cmake to build the final programm
