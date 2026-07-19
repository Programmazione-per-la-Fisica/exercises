add_executable(string_to_integer.out string_to_integer.cpp)
target_include_directories(string_to_integer.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME string_to_integer.out COMMAND string_to_integer.out)