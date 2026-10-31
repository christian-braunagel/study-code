cmake_minimum_required(VERSION 3.16)

project(StatusAnalyzer
        VERSION 1.0.0
        LANGUAGES CXX)

add_library(analyzer_core STATIC src/status_analyzer.cpp)
target_include_directories(analyzer_core PUBLIC include)
target_compile_features(analyzer_core PUBLIC cxx_std_17)

add_executable(StatusAnalyzer src/main.cpp)

target_link_libraries(StatusAnalyzer PRIVATE analyzer_core)

find_package(GTest REQUIRED) # GTest is the name of the package

include(CTest)
include(GoogleTest) # GoogleTest is a helper module shipped with CMake
enable_testing()

add_executable(test_analyzer tests/status_analyzer_tests.cpp)
target_link_libraries(test_analyzer PRIVATE analyzer_core GTest::gtest_main)

gtest_discover_tests(test_analyzer)
