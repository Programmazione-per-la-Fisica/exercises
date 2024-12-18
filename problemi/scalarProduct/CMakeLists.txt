add_executable(scalarProd.out scalarProduct.cpp)
target_include_directories(scalarProd.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME scalarProd.out COMMAND scalarProd.out)
