cmake_minimum_required(VERSION 3.28)
project(laba1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(laba1 main.cpp
        Array.cpp
        Array.h
        menu.cpp
        menu.h
)
