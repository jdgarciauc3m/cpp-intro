cmake_minimum_required(VERSION 3.19)
project(fecha_oper
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(fecha_oper main.cpp fecha.cpp)