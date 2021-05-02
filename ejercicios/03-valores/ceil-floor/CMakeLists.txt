cmake_minimum_required(VERSION 3.19)
project(ceil_floor)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Werror -Wpedantic -Werror -pedantic-errors
                    -Wconversion)

add_executable(ceil_floor main.cpp)