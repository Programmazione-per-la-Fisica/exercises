add_executable(maxAdjProd.out maxAdjProd.cpp)
target_include_directories(maxAdjProd.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME maxAdjProd.out COMMAND maxAdjProd.out)

add_executable(maxAdjProd_algo.out maxAdjProd_algo.cpp)
target_include_directories(maxAdjProd_algo.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME maxAdjProd_algo.out COMMAND maxAdjProd_algo.out)
