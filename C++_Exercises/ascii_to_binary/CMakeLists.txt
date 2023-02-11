cmake_minimum_required(VERSION 3.22.1)

project(ascii_to_binary)

set(CMAKE_CXX_STANDARD 23)

add_executable(ascii_to_binary ascii_to_binary.cpp operations.h)