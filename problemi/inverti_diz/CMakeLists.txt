add_executable(inverti_diz.out inverti_diz.cpp)
target_include_directories(inverti_diz.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME inverti_diz.out COMMAND inverti_diz.out)