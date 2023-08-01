cmake_minimum_required(VERSION 3.9.1)

project(findfile)

set(CMAKE_CXX_STANDARD 17)

set(LIB_SOURCES
    findfile.cpp
)

add_library(findfile STATIC ${LIB_SOURCES})

target_include_directories(findfile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
