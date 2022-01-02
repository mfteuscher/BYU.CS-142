cmake_minimum_required(VERSION 3.21)
project(CS142-Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS142-Lab2
        "Lab 5.cpp")

file(GLOB MY_FILES "*.txt")
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})