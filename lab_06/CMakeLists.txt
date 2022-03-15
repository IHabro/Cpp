cmake_minimum_required(VERSION 3.8)
project(tasks06)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# add_compile_options(-Wall -Wextra -pedantic)

add_executable(main main.cpp)
