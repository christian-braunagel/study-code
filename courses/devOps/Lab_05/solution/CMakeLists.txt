cmake_minimum_required(VERSION 3.20)

project(ChessApp
        VERSION 0.1.11
        LANGUAGES C)

add_library(chess-core STATIC
            src/board.c
            src/move.c
            src/util.c)

target_include_directories(chess-core
    PUBLIC include
)

target_compile_features(chess-core
    PUBLIC c_std_11
)

add_executable(chess-app
                src/main.c)

target_compile_definitions(chess-app
    PRIVATE STARTING_TIME=300
)

target_link_libraries(chess-app
                    PRIVATE chess-core)

# How to build the test target
# cmake --build build --target test-move
# .\build\test-move.exe

add_executable(test-move
               tests/test_move.c)

target_link_libraries(test-move
                    PRIVATE chess-core)

# Note: PRIVATE not PUBLIC
if(MSVC)
    target_compile_options(chess-core PRIVATE /W4 /WX)
    target_compile_options(chess-app PRIVATE /W4 /WX)
    target_compile_options(test-move PRIVATE /W4 /WX)
else()
    target_compile_options(chess-core PRIVATE -Wall -Wextra -Werror -g)
    target_compile_options(chess-app PRIVATE -Wall -Wextra -Werror -g)
    target_compile_options(test-move PRIVATE -Wall -Wextra -Werror -g)
endif()


