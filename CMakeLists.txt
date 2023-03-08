# CMakeList.txt: проект CMake для Program_parallelization; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.15)

project (8.Program_parallelization)

add_executable(Program_parallelization    
    src/main.cpp
    src/parallelization.cpp
 )
  
set_property(TARGET Program_parallelization PROPERTY CXX_STANDARD 20)

target_include_directories(Program_parallelization PRIVATE include)
