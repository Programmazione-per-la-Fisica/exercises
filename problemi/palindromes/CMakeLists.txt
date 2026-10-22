set(CMAKE_CXX_STANDARD 20)

add_executable(is_palindrome.out is_palindrome.cpp)

add_executable(is_palindrome_test.out is_palindrome_test.cpp)
target_include_directories(is_palindrome_test.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME is_palindrome_test.out COMMAND is_palindrome_test.out)
