cmake_minimum_required(VERSION 3.19)
project(fecha_ctor
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(fecha_ctor main.cpp fecha.cpp)