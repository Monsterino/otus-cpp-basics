cmake_minimum_required(VERSION 3.5)

project(06.homework)



add_executable(containers 
			   src/main.cpp
			   src/test.cpp)

target_include_directories(containers PRIVATE include)

set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

