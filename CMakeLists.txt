cmake_minimum_required(VERSION 3.24)
project(Storage)

set(CMAKE_CXX_STANDARD 17)

add_executable(Storage source/main.cpp source/storage_types.cpp source/package.cpp include/package.hpp include/storage_types.hpp include/types.hpp)

include_directories( ./include )
