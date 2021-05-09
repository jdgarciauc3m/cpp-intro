cmake_minimum_required(VERSION 3.19)
project(decl)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(decl1 main1.cpp)
add_executable(decl2 main2.cpp)
add_executable(decl3 main3.cpp)