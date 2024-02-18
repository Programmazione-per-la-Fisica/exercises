add_executable(kaprekar.out kaprekar.cpp)
target_include_directories(kaprekar.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME kaprekar.out COMMAND kaprekar.out)
