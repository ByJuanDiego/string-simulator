cmake_minimum_required(VERSION 3.24)
project(string_simulator)

include_directories("./include")

set(CMAKE_CXX_STANDARD 20)

add_executable(string_simulator main.cpp src/string.cpp include/string.hpp)
