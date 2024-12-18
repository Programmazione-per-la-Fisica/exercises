add_executable(vecRot.out vectorRotation.cpp)
target_include_directories(vecRot.out PRIVATE ${DOCTEST_INCLUDE_DIR})
add_test(NAME vecRot.out COMMAND vecRot.out)
