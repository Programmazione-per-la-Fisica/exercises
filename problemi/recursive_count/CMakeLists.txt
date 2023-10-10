cmake_minimum_required(VERSION 3.9.1)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the C++ flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

# Set the folder for the executable
set(EXECUTABLE_OUTPUT_PATH ../)

# Compile
add_executable(recursive_count.out ./recursive_count.cpp ../../doctest.h)
add_test(NAME recursive_count.out COMMAND recursive_count.out)
