add_executable(minFuncDistance.out minFuncDistance.cpp)
target_include_directories(minFuncDistance.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME minFuncDistance.out COMMAND minFuncDistance.out)

add_executable(minFuncDistance_algo.out minFuncDistance_algo.cpp)
target_include_directories(minFuncDistance_algo.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME minFuncDistance_algo.out COMMAND minFuncDistance_algo.out)
