cmake_minimum_required(VERSION 3.0)

project("Longest Collatz Sequence")

# Application executable
add_executable(app main.cpp collatz.cpp)
set_property(TARGET app PROPERTY CXX_STANDARD 17)
target_compile_definitions(app PUBLIC DOCTEST_CONFIG_DISABLE)

# Test executable
add_executable(test collatz.cpp)
set_property(TARGET test PROPERTY CXX_STANDARD 17)
target_compile_definitions(test PUBLIC DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
