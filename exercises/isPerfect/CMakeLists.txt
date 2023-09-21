cmake_minimum_required(VERSION 3.9.1)

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
add_executable(isPerfect.out ./isPerfect.cpp)
target_include_directories(isPerfect.out SYSTEM PRIVATE ${doctest_SOURCE_DIR}/doctest)
add_test(NAME isPerfect.out COMMAND isPerfect.out)
add_executable(isPerfect_algo.out ./isPerfect_algo.cpp)
target_include_directories(isPerfect_algo.out SYSTEM PRIVATE ${doctest_SOURCE_DIR}/doctest)
add_test(NAME isPerfect_algo.out COMMAND isPerfect_algo.out)
