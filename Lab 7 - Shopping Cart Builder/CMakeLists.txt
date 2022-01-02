cmake_minimum_required(VERSION 3.21)
project(CS142-Lab7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS142-Lab7
        ItemToPurchase.cpp
        ItemToPurchase.h
        main.cpp
        ShoppingCart.cpp
        ShoppingCart.h)
