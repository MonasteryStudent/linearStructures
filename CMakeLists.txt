cmake_minimum_required(VERSION 3.16)

project(linkedMemory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library target
add_library(linkedMemory INTERFACE)

# Tell CMake where headers live
target_include_directories(linkedMemory INTERFACE src)

# Test executable
add_executable(test_insert
    tests/test_insert.cpp
)

# Link test against the library
target_link_libraries(test_insert linkedMemory)
