add_executable(elimina_uguali_cons.out elimina_uguali_cons.cpp)
target_include_directories(elimina_uguali_cons.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME elimina_uguali_cons.out COMMAND elimina_uguali_cons.out)