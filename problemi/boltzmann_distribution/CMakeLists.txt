find_package(ROOT REQUIRED COMPONENTS Hist Graf Graf3d Gpad)

add_subdirectory(src)

add_executable(boltzmann_distribution.out boltzmann_distribution.cpp)
target_link_libraries(boltzmann_distribution.out PRIVATE ROOT::Hist ROOT::Graf ROOT::Graf3d ROOT::Gpad)
target_link_libraries(boltzmann_distribution.out PRIVATE boltzmann_lib)

if (BUILD_TESTING)
    add_executable(boltzmann_distribution_test.out boltzmann_distribution.test.cpp)
    target_link_libraries(boltzmann_distribution_test.out PRIVATE boltzmann_lib)
    target_include_directories(boltzmann_distribution_test.out PRIVATE ${DOCTEST_INCLUDE_DIR})
    add_test(NAME boltzmann_distribution_test.out COMMAND boltzmann_distribution_test.out 1000 1000,10000,100000)
endif()