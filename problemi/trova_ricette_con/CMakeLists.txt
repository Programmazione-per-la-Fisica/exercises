add_executable(trova_ricette_con.out trova_ricette_con.cpp)
target_include_directories(trova_ricette_con.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME trova_ricette_con.out COMMAND trova_ricette_con.out)