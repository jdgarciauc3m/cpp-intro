cmake_minimum_required(VERSION 3.19)
project(calendario)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest)

add_executable(calendario_test util.cpp util_test.cpp)
target_link_libraries(calendario_test GTest::GTest GTest::Main)
gtest_discover_tests(calendario_test)