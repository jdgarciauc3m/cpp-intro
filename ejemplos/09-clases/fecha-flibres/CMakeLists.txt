cmake_minimum_required(VERSION 3.19)
project(fecha-flibres)

set(CMAKE_CXX_STANDARD 20)

find_package(mincontracts REQUIRED)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(fecha main.cpp fecha.cpp)
target_link_libraries(fecha mincontracts::mincontracts)