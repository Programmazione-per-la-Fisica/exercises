add_executable(vec_ops_basic basic.cpp)

add_executable(vec_ops_intermediate.t intermediate.cpp)
target_include_directories(vec_ops_intermediate.t PRIVATE ${DOCTEST_INCLUDE_DIR})
