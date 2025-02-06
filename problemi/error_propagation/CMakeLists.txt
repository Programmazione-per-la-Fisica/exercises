set(CMAKE_CXX_STANDARD 20)

add_executable(propagate_errors.out propagate_errors.cpp)
target_include_directories(propagate_errors.out PRIVATE ${DOCTEST_INCLUDE_DIR})
