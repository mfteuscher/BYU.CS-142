cmake_minimum_required(VERSION 3.21)
project(CS142-Lab9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS142-Lab9
        BakedGood.cpp
        BakedGood.h
        Bread.cpp
        Bread.h
        Cake.cpp
        Cake.h
        CupCake.cpp
        CupCake.h
        LayerCake.cpp
        LayerCake.h
        main.cpp)
