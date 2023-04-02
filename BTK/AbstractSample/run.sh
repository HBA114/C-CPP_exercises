#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./AbstractSample
cd ..
rm -r build
