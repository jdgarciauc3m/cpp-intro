cmake_minimum_required(VERSION 3.19)
project(enlace)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors -Wconversion)

add_executable(enlace main.cpp)