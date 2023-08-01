cmake_minimum_required(VERSION 3.9.1)
set(CMAKE_C_COMPILER "gcc-4.2")
set(CMAKE_CXX_COMPILER "/bin/g++-4.2")

project(app)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SOURCES findingfile.cpp)

add_subdirectory(../findfile ${CMAKE_BINARY_DIR}/findfile_build)

add_executable(app ${SOURCES})
target_link_libraries(app PRIVATE findfile)

