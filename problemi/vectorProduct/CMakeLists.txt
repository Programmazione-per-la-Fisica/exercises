add_executable(vecProd.out vectorProduct.cpp)
target_include_directories(vecProd.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME vecProd.out COMMAND vecProd.out)
