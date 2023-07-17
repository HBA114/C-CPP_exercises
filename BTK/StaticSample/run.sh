#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./StaticSample
cd ..
rm -r build
