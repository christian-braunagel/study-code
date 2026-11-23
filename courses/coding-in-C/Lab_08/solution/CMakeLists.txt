cmake_minimum_required(VERSION 3.10)

project(playlist_app C)

# C-Standard festlegen
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include-Verzeichnis
include_directories(include)

# --------------------------------------------------
# Produktivcode als Library
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
# CTest aktivieren
# --------------------------------------------------

enable_testing()

add_test(
    NAME PlaylistUnitTests
    COMMAND test_playlist
)

# --------------------------------------------------
# Tests vor jedem Build erzwingen
# --------------------------------------------------

# Custom Target zum Ausführen der Tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_playlist
    COMMENT "Running unit tests"
)

# --------------------------------------------------
#  Hauptprogramm
# --------------------------------------------------

# Executable definieren
add_executable(playlist_app
    main.c
    src/playlist.c
)

target_link_libraries(playlist_app
    playlist
)

# Hauptprogramm darf nur gebaut werden,
# wenn die Unit-Tests erfolgreich waren
add_dependencies(playlist_app run_tests)