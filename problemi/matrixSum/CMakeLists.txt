add_executable(matSum.out matrixSum.cpp)
target_include_directories(matSum.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME matSum.out COMMAND matSum.out)
