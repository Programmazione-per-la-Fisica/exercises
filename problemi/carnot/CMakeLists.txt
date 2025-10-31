add_executable(carnot.out carnot.cpp)
target_include_directories(carnot.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME carnot.out COMMAND carnot.out)