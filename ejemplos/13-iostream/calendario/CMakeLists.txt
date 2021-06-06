cmake_minimum_required(VERSION 3.19)
project(calendario
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(calendario main.cpp mes.cpp fecha.cpp)