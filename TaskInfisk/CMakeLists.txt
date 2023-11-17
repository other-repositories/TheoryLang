cmake_minimum_required(VERSION 3.12)
project(TaskInfix)

set(CMAKE_CXX_STANDARD 17)

add_executable(tests
    tests.cpp 
    inter.cpp
)

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS "-lgcov")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

target_include_directories(tests PUBLIC mettle/include)
