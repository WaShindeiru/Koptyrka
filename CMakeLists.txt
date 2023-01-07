cmake_minimum_required(VERSION 3.24)
project(kot)

set(CMAKE_CXX_STANDARD 20)

add_executable(kot main.cpp src/package.cpp include/package.hpp)
