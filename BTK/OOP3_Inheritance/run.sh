#!/bin/bash
mkdir build
cd build
cmake ..
make
clear
./OOP3_Inheritance
cd ..
rm -r build