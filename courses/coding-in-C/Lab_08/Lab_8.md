# Lab 8: Modular Playlist Manager

## Section I

### Introduction
In this lab, you will enhance your existing playlist program by making it modular.  
The goal is to **separate declarations and implementations** and use **header files** to structure your program.

You will learn:

- how to organize C code into multiple files
- how to use `struct` and `typedef` in a modular program
- how to use **header guards** to avoid multiple inclusions
- how to maintain and extend code more easily

### Requirements

1. Create three files:
   - `playlist.h` → declarations of structs and functions
   - `playlist.c` → implementation of playlist functions
   - `main.c` → main program that uses the playlist API

2.  Use the following folder structure:
    
```text
project/
├── main.c
├── src/
│   └── playlist.c
└── include/
    └── playlist.h
```

3. Use **header guards** in `playlist.h`.

4. Introduce a **preprocessor macro `MAX_SONGS`** in `playlist.h`:
   - Defines the **maximum number of songs allowed in a playlist**
   - `add_song` must **check this limit** before adding a new song
   - If the limit is reached, print an error message and do not add the song

### Hints

- The `playlist.h` file should only contain **declarations**, not function definitions
- Use the following command in the terminal to build the app: gcc -I./include main.c src/playlist.c -o playlist_app
- Note: The option "-I ./include" adds an additional include path, so that the compiler would now search first in the current folder of the corresponding c-file, then in the ./include path and finally in the system include paths. This can be neccessary depending on how you included your header because "playlist.h" is no longer stored in the same folder as main.c.
- Note: The order of the mentioned c-files in the gcc command is arbitrarily.
- Use the following command to run the build app via terminal: .\playlist_app.exe
- Not: The command above needs to be adjusted on other operating systems (usually without .exe and with ./)

## Section II: Unit-Testing your Project

Section II will focus on how to use standard library <assert.h> to create and execute some unit-tests.

### Requirements

1. Navigate into your project folder and create a new folder called "test".
2. Create a new file with the name "test_playlist.c".
3. Use the following code as template for this file:
```c
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist p;
    init_playlist(&p);

    assert(p.p_head == NULL);
    assert(p.size == 0);
}

/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}

```
4. Now update the file and add one unit-test for each test-function listed in main().
5. To build and run the test, you need to execute the following commands:
   * ``` gcc -I ./include -c src/playlist.c -o playlist.o```: First the playlist.c is compiled. However, due to option -c it will not be linked.
   * ``` gcc -I ./include test/test_playlist.c playlist.o -o test_playlist```: Builds and links test program
   * ``` ./test_playlist ```: Run test program and check output. If tests fail, rework your code. If successful, build the app.
   * ``` gcc -I ./include src/main.c playlist.o -o playlist_app ```: Build and link app
6. Change one of the test cases in a way, that it fails (Fail on purpose) to verify that the unit-tests work.

## Section III: Building the Project with CMake

This section explains how to build the project using **CMake** on all major operating systems.  
CMake is a cross-platform build system generator that creates platform-specific build files.

As you might experienced in section II, it can become quite cumbersome to manually run the gcc tool for each unit test file and c-file over and over again. Build tools can help to simplify and automate the task.

### Requirements

1. Check if cmake is already installed by using: cmake --version
2. If not: Install cmake

   - Windows: Download the installer (.msi) from [cmake.org](https://cmake.org/download/). Check the box "Add CMake to Path" in installer
   - Linux: sudo apt install cmake
   - macOS: brew install cmake

3. Navigate into your project of section I and create a file called CMakeLists.txt
4. Copy the following content into it:

```C
cmake_minimum_required(VERSION 3.10)

project(playlist_app C)

# C-Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include-folders
include_directories(include)

# --------------------------------------------------
# Library
# --------------------------------------------------

add_library(playlist
    src/playlist.c
)

# --------------------------------------------------
# Unit-Test-Executable
# --------------------------------------------------

add_executable(test_playlist
    test/test_playlist.c
)

target_link_libraries(test_playlist
    playlist
)

# --------------------------------------------------
# Activate CTest
# --------------------------------------------------

enable_testing()

add_test(
    NAME PlaylistUnitTests
    COMMAND test_playlist
)

# --------------------------------------------------
# Ensure testing before each build
# --------------------------------------------------

# Custom Target to execute tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_playlist
    COMMENT "Running unit tests"
)

# --------------------------------------------------
#  Main
# --------------------------------------------------

# Executable
add_executable(playlist_app
    main.c
    src/playlist.c
)

target_link_libraries(playlist_app
    playlist
)

# only build main if tests successful
add_dependencies(playlist_app run_tests)

```
Explanations to cmake:
   * ``` cmake_minimum_required(VERSION 3.10) ```: Sets the minimum required version of CMake to ensure feature availability
   * ``` project(playlist_app C) ```: Defines project name and programming language (C).
   * ``` set(CMAKE_C_STANDARD 11) ```: Defines the standard C11 should be used.
   * ``` set(CMAKE_C_STANDARD_REQUIRED ON) ```: Ensures that no older standards can be used.
   * ``` include_directories(include) ```: Adds the include folder to the compiler search path.
   * ``` add_library(playlist src/playlist.c) ```: Creates a library called playlist that can be reused by each executable.
   * ``` add_executable(test_playlist test/test_playlist.c) ```: Creates an executable program (here for running unit tests).
   * ``` target_link_libraries(test_playlist playlist) ```: Links an executable (here test_playlist) with a library (here playlist).
   * ``` enable_testing() ```: Activates CTest, CMake’s built-in test runner.
   * ``` add_test(NAME PlaylistUnitTests COMMAND test_playlist)```: Defines a CTest test (PlaylistUnitTests) that runs the executable (test_playlist). If any assert fails in this executable, then the test fails and CTest reports it.
   * ``` add_custom_target(run_tests COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure DEPENDS test_playlist COMMENT "Running unit tests")```: Build a target that can execute commands. Here, the target run_tests is build that calls CTest which then runs all tests defined with add_test().
   * ``` add_dependencies(playlist_app run_tests) ```: Ensures playlist_app is only built if run_tests succeeds.

5. Create a folder called build in the project and navigate into it
6. Run the following command to create a Makefile that uses MinGW:
```bash
cmake -G "MinGW Makefiles" ..    # command for local Windows machine
```
or
```bash
cmake ..    # command for Unix-based GitHub codespaces
```
7. Then build the project and execute the tests in parallel with:
```c
cmake --build .
```
8. Now you can run the created playlist_app.exe in the build folder.
