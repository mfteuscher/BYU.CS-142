cmake_minimum_required(VERSION 3.21)
project(CS142-Lab8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS142-Lab8
        main.cpp
        Playlist.cpp
        Playlist.h
        Song.cpp
        Song.h)
