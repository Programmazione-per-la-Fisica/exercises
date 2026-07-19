add_executable(trova_sequenza.out trova_sequenza.cpp)
target_include_directories(trova_sequenza.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME trova_sequenza.out COMMAND trova_sequenza.out)