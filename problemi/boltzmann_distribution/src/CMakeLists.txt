add_library(boltzmann_lib STATIC
    boltzmann.cpp
)

target_include_directories(boltzmann_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/
)