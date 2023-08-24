cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 23)

project(heap)
add_subdirectory (src)

enable_testing ()
add_subdirectory (test)