cmake_minimum_required(VERSION 3.12)

project(03.homework_3)

add_executable(homework_3 
    guess_the_number.cpp
    utils.cpp
    utils.h
)

set_target_properties(homework_3 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
