cmake_minimum_required(VERSION 3.10)

project(playlist_app C)

# C-Standard festlegen
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include-Verzeichnis
include_directories(include)

# Executable definieren
add_executable(playlist_app
    main.c
    src/playlist.c
)
