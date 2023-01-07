cmake_minimum_required(VERSION 3.24)
project(Storage)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Storage
        source/main.cpp
        source/package.cpp
        source/storage_types.cpp
        include/types.hpp
        include/storage_types.hpp)
