add_executable(recursive_count.out recursive_count.cpp)
target_include_directories(recursive_count.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME recursive_count.out COMMAND recursive_count.out)
