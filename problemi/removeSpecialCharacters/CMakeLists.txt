add_executable(rmSpecialChars.out rmSpecialChars.cpp)
target_include_directories(rmSpecialChars.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME rmSpecialChars.out COMMAND rmSpecialChars.out)

add_executable(rmSpecialChars_algo.out rmSpecialChars_algo.cpp)
target_include_directories(rmSpecialChars_algo.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME rmSpecialChars_algo.out COMMAND rmSpecialChars_algo.out)
