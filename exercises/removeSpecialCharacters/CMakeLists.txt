cmake_minimum_required(VERSION 3.9.1)

project(removeSpecialCharacters VERSION 1.0.0 LANGUAGES CXX)

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
add_executable(rmSpecialChars.out ./rmSpecialChars.cpp)
target_include_directories(rmSpecialChars.out SYSTEM PRIVATE ${doctest_SOURCE_DIR}/doctest)
add_test(NAME rmSpecialChars.out COMMAND rmSpecialChars.out)
add_executable(rmSpecialChars_algo.out ./rmSpecialChars_algo.cpp)
target_include_directories(rmSpecialChars_algo.out SYSTEM PRIVATE ${doctest_SOURCE_DIR}/doctest)
add_test(NAME rmSpecialChars_algo.out COMMAND rmSpecialChars_algo.out)
