add_executable(inverti_map.out inverti_map.cpp)
target_include_directories(inverti_map.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME inverti_map.out COMMAND inverti_map.out)