cmake_minimum_required(VERSION 3.24)
project(Storage)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES
        source/package.cpp
        source/storage_types.cpp
        )

add_executable(Storage source/main.cpp)


#Google Test Framework
set(SOURCES_FILES_TESTS
        test/test_package.cpp
        test/test_storage_types.cpp
        )

add_executable(NetSim_tests ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

target_include_directories(NetSim_tests PUBLIC
        googletest-master/googlemock/include
        googletest-master/googletest/include
        mocks
        )

add_subdirectory(googletest-master)
target_link_libraries(NetSim_tests gmock)
target_compile_definitions(Storage PUBLIC EXERCISE_ID=1)
