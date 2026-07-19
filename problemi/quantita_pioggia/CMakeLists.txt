add_executable(quantita_pioggia.out quantita_pioggia.cpp)
target_include_directories(quantita_pioggia.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME quantita_pioggia.out COMMAND quantita_pioggia.out)