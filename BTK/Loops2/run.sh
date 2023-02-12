#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./Loops2
cd ..
rm -r build