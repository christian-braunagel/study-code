cmake_minimum_required(VERSION 3.16)

project(StatusAnalyzer VERSION 1.0.0 LANGUAGES CXX)

add_library(analyzer_core STATIC src/status_analyzer.cpp)
target_include_directories(analyzer_core PUBLIC include)
target_compile_features(analyzer_core PUBLIC cxx_std_17)

# Enable GCC coverage instrumentation.
# PUBLIC also enables coverage for executables linking this library.
target_compile_options(analyzer_core PUBLIC --coverage -O0 -g)
target_link_options(analyzer_core PUBLIC --coverage)

add_executable(status_analyzer_app src/main.cpp)
target_link_libraries(status_analyzer_app PRIVATE analyzer_core)

find_package(GTest REQUIRED)
include(CTest)
include(GoogleTest)

add_executable(test_analyzer tests/status_analyzer_tests.cpp)
target_link_libraries(test_analyzer PRIVATE analyzer_core GTest::gtest_main)
gtest_discover_tests(test_analyzer)
