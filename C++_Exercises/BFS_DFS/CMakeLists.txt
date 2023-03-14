cmake_minimum_required(VERSION 3.22.1)

project(BFS_DFS)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(libs)

add_executable(BFS_DFS main.cpp)

target_link_libraries(BFS_DFS PRIVATE libraries)
