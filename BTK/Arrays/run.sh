#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./Arrays
cd ..
rm -r build