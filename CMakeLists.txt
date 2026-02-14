# CMake is a build system generator, that does not compile code.
# It generates build files (Makefiles, Ninja files, VS project files, etc.).
# CMakeLists.txt is a declarative build description, not a script.
# Here we describe what exists, and CMake figures out how to build it.

option(LINEAR_STRUCTURES_BUILD_TESTS "Build linearStructures tests" ON)

cmake_minimum_required(VERSION 3.16)

project(linearStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library target
add_library(linearStructures INTERFACE)
# Tell CMake where headers live
target_include_directories(linearStructures INTERFACE src)

if(LINEAR_STRUCTURES_BUILD_TESTS)

    # Enable CTest
    enable_testing()

    # Tests List
    # push_front
    # Test executable
    add_executable(test_list_push_front tests/list/test_list_push_front.cpp) 
    # Link test against the library
    target_link_libraries(test_list_push_front linearStructures) 
    # Tell CTest about the test you want to add
    add_test(NAME list_push_front COMMAND test_list_push_front) 
    # pop_back
    add_executable(test_list_pop_back tests/list/test_list_pop_back.cpp)
    target_link_libraries(test_list_pop_back linearStructures)
    target_include_directories(test_list_pop_back PRIVATE tests)
    add_test(NAME list_pop_back COMMAND test_list_pop_back)
    # pop_front
    add_executable(test_list_pop_front tests/list/test_list_pop_front.cpp)
    target_link_libraries(test_list_pop_front linearStructures)
    add_test(NAME list_pop_front COMMAND test_list_pop_front)
    # front
    add_executable(test_list_front tests/list/test_list_front.cpp)
    target_link_libraries(test_list_front linearStructures)
    add_test(NAME list_front COMMAND test_list_front)
    # Test List back
    add_executable(test_list_back tests/list/test_list_back.cpp)
    target_link_libraries(test_list_back linearStructures)
    add_test(NAME list_back COMMAND test_list_back)

    # Tests Vector 
    # push_back
    add_executable(test_vector_push_back tests/vector/test_vector_push_back.cpp)
    target_link_libraries(test_vector_push_back linearStructures)
    add_test(NAME vector_push_back COMMAND test_vector_push_back)
    # pop_back
    add_executable(test_vector_pop_back tests/vector/test_vector_push_back.cpp)
    target_link_libraries(test_vector_pop_back linearStructures)
    target_include_directories(test_vector_pop_back PRIVATE tests)
    add_test(NAME vector_pop_back COMMAND test_vector_pop_back)
    # front
    add_executable(test_vector_front tests/vector/test_vector_front.cpp)
    target_link_libraries(test_vector_front linearStructures)
    target_include_directories(test_vector_front PRIVATE tests)
    add_test(NAME test_vector_front COMMAND test_vector_front)

    # Tests Queue 
    # push
    add_executable(test_queue_push tests/queue/test_queue_push.cpp)
    target_link_libraries(test_queue_push linearStructures)
    add_test(NAME queue_push COMMAND test_queue_push)
    # pop
    add_executable(test_queue_pop tests/queue/test_queue_pop.cpp)
    target_link_libraries(test_queue_pop linearStructures)
    add_test(NAME queue_pop COMMAND test_queue_pop)

    # Test Stack 
    # push
    add_executable(test_stack_push tests/stack/test_stack_push.cpp)
    target_link_libraries(test_stack_push linearStructures)
    add_test(NAME stack_push COMMAND test_stack_push)
    # pop
    add_executable(test_stack_pop tests/stack/test_stack_pop.cpp)
    target_link_libraries(test_stack_pop linearStructures)
    target_include_directories(test_stack_pop PRIVATE tests)
    add_test(NAME stack_pop COMMAND test_stack_pop)

endif()
