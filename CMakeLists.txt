cmake_minimum_required(VERSION 3.12)

project(02.homework_1)

add_executable(homework_1 
    hello_world.cpp
    example.cpp
    example.h
)

set_target_properties(homework_1 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)