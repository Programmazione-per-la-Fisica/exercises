add_executable(hanoi.out hanoi.cpp)
target_include_directories(hanoi.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME hanoi.out COMMAND hanoi.out)
