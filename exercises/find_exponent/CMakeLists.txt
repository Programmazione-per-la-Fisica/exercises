cmake_minimum_required(VERSION 3.9.1)

project(find_exponent VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the C++ flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

# Set the folder for the executable
set(EXECUTABLE_OUTPUT_PATH ../)

include(FetchContent)

# Get doctest
FetchContent_Declare(doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG 7b9885133108ae301ddd16e2651320f54cafeba7
)
FetchContent_GetProperties(doctest)
if(NOT doctest_POPULATED)
  FetchContent_Populate(doctest)
endif()

# Compile
add_executable(find_exponent.out ./find_exponent.cpp)
target_include_directories(find_exponent.out SYSTEM PRIVATE ${doctest_SOURCE_DIR}/doctest)
add_test(NAME find_exponent.out COMMAND find_exponent.out)
