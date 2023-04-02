#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./ConstantSample
cd ..
rm -r build
