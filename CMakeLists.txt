cmake_minimum_required(VERSION 3.5)

project(10.TikTakToe)



add_executable(TikTakToe 
			   src/main.cpp
			   src/Game.cpp
			   src/Game_interface.cpp)

target_include_directories(TikTakToe PRIVATE include)

set_target_properties(TikTakToe PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

