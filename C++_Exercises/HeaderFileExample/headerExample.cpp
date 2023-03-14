#include <iostream>
#include "computate.hpp"

int main()
{
    std::cout << "Double of 3 is " << double_member(3) << std::endl;
    std::cout << "10 C degree =  " << celcius_to_fahrenheit(10) << std::endl;
    return 0;
}

// Compile this program with this command : g++ headerExample.cpp computate.cpp -o headerExample
// run .\headerExample
