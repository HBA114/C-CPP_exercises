#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./Loops
cd ..
rm -r build