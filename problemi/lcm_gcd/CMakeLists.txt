add_executable(lcm_gcd.out lcm_gcd.cpp)
target_include_directories(lcm_gcd.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME lcm_gcd.out COMMAND lcm_gcd.out)
