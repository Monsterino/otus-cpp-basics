cmake_minimum_required(VERSION 3.5)

project(07.homework)

find_package(GTest)

add_executable(containers 
			   src/main.cpp
			   )

target_include_directories(containers PRIVATE include)


add_executable(test_list
			   test/test_list/test_list.cpp
			   test/test_vector/test_vector.cpp
			   test/test.cpp)


target_include_directories(
    test_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_include_directories(
    test_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_include_directories(
    test_list PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(
    test_list PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)



if (MSVC)
    target_compile_options(
        containers PRIVATE
        /W4
    )
    target_compile_options(
        test_list PRIVATE
        /W4
    )
else ()
    target_compile_options(
        containers PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_list PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

