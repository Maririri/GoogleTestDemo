cmake_minimum_required(VERSION 3.4)
project(GoogleTestDemo)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest)


include_directories(lib/googletest/googletest/include)
#include_directories(lib/googletest/googlemock/include)
set(SOURCE_FILES main.cpp src/TestWithFixture.cpp src/TypedTests.cpp src/MockTests.cpp src/ParameterTests.cpp)
add_executable(GoogleTestDemo ${SOURCE_FILES})
target_link_libraries(GoogleTestDemo gtest gtest_main  gmock gmock_main)