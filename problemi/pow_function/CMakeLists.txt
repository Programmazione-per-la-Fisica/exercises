add_executable(pow.out pow.cpp)
target_include_directories(pow.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME pow.out COMMAND pow.out)
