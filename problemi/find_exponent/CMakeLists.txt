add_executable(find_exponent.out find_exponent.cpp)
target_include_directories(find_exponent.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME find_exponent.out COMMAND find_exponent.out)
