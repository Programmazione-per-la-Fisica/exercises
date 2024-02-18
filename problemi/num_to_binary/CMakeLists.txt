add_executable(num_to_binary.out num_to_binary.cpp)
target_include_directories(num_to_binary.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME num_to_binary.out COMMAND num_to_binary.out)
