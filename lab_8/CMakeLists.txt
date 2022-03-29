cmake_minimum_required(VERSION 3.8)
project(practice08)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
add_compile_options(-Wall -Wextra -pedantic)

# add_executable(string string.cpp)
# add_executable(string_view string_view.cpp)
add_executable(stream stream.cpp)

# add_executable(test student_tests.cpp student.cpp)