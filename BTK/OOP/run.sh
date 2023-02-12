#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./OOP
cd ..
rm -r build