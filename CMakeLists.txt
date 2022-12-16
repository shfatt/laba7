# CMakeList.txt : CMake project for 7.1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME 7)
project ("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS off)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories("inc/")

add_executable ("${PROJECT_NAME}" "7.cpp")

file(COPY input.txt DESTINATION "/");
