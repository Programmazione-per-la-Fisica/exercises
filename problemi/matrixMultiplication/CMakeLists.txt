add_executable(matMult.out matrixMultiplication.cpp)
target_include_directories(matMult.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME matMult.out COMMAND matMult.out)

