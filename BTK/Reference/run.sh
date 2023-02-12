#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./Reference
cd ..
rm -r build