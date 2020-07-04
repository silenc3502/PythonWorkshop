cmake_minimum_required(VERSION 3.7)
project(stdcyt)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        std.h
        std.cpp
        )

include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(stdcyt ${SOURCE_FILES})
