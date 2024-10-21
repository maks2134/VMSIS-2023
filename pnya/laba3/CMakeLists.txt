cmake_minimum_required(VERSION 3.28)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp
        Auto.cpp
        Auto.h
        cargo.cpp
        cargo.h
        passanger.cpp
        passanger.h
        Bus.cpp
        Bus.h
        troll.cpp
        troll.h
        dump.cpp
        dump.h
        menu.cpp
        menu.h)
