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
add_executable(find_exponent.out ./find_exponent.cpp ../../doctest.h)
add_test(NAME find_exponent.out COMMAND find_exponent.out)
