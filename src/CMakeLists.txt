include_directories(../include)
add_executable(heap main.cpp)
add_definitions(-DNDEBUG) # disables asserts
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -march=native")