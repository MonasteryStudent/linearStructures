cmake_minimum_required(VERSION 3.16)

project(linearStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library target
add_library(linearStructures INTERFACE)
# Tell CMake where headers live
target_include_directories(linearStructures INTERFACE src)

# Enable CTest
enable_testing()

# Test List push_front
# Test executable
add_executable(test_list_push_front tests/test_list_push_front.cpp)
# Link test against the library
target_link_libraries(test_list_push_front linearStructures)
# Tell CTest about the test you want to add
add_test(NAME list_push_front COMMAND test_list_push_front)

# Test List pop_back
add_executable(test_list_pop_back tests/test_list_pop_back.cpp)
target_link_libraries(test_list_pop_back linearStructures)
add_test(NAME list_pop_back COMMAND test_list_pop_back)

# Test Vector push_back
add_executable(test_vector_push_back tests/test_vector_push_back.cpp)
target_link_libraries(test_vector_push_back linearStructures)
add_test(NAME vector_push_back COMMAND test_vector_push_back)
