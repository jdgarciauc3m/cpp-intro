cmake_minimum_required(VERSION 3.19)
project(cabeceras)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(area main.cpp geom.cpp)