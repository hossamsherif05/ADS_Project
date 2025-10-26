cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        graph.cpp
        graph.h
        queue.h
        queue.cpp
)
