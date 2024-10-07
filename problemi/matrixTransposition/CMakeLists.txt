add_executable(matTranspose.out matrixTranspose.cpp)
target_include_directories(matTranspose.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME matTranspose.out COMMAND matTranspose.out)
