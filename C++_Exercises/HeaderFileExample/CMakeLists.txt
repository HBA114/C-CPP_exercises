cmake_minimum_required(VERSION 3.22.1)

project(HeaderFileExample)

set(CMAKE_CXX_STANDARD 23)

add_executable(HeaderFileExample headerExample.cpp computate.cpp computate.hpp)