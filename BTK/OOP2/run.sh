#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./OOP2
cd ..
rm -r build