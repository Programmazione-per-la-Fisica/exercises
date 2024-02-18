cmake_minimum_required(VERSION 3.16.0)

project(PF_Exercises VERSION 1.0.0 LANGUAGES CXX)

# abilita il supporto per i test
include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -Wextra-semi -Wdouble-promotion -Wimplicit-fallthrough")
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

set(DOCTEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/doctest)

add_subdirectory(problemi)
