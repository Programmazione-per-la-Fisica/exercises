add_executable(is_prime.out is_prime.cpp)
target_include_directories(is_prime.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME is_prime.out COMMAND is_prime.out)
