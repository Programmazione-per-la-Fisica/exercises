add_executable(calculate_pi.out calculate_pi.cpp)
target_include_directories(calculate_pi.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME calculate_pi.out COMMAND calculate_pi.out)
