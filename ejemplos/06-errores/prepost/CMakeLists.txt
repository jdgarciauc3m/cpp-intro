cmake_minimum_required(VERSION 3.19)
project(prepost
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(nocheck nocheck.cpp)
add_executable(check check.cpp)
add_executable(contract-check contract_check.cpp)
