cmake_minimum_required(VERSION 3.16)

project(SearchEngineApp
    VERSION 1.0
    LANGUAGES CXX
)

add_executable(searchEngineApp
    searchengine_main.cpp
    searchEngine.cpp
    searchQuery.cpp
    webResource.cpp
)

target_compile_features(searchEngineApp PRIVATE cxx_std_17)

set_target_properties(searchEngineApp PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_include_directories(searchEngineApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
