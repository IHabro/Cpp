cmake_minimum_required(VERSION 3.4)
project(practice02)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_compile_options(-Wall -Wextra -pedantic)

add_executable(functions functions.cpp)
add_executable(casts casts.cpp)
add_executable(references references.cpp)
add_executable(lambdas lambdas.cpp)
