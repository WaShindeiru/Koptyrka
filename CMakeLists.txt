cmake_minimum_required(VERSION 3.24)
project(Storage)

set(CMAKE_CXX_STANDARD 17)

add_executable(Storage source/main.cpp)

include_directories( ./include )
