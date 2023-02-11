#ifndef cat
#define cat
#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

class Cat : public Animal
{
public: // if you forget this access modifier you can not run main.cpp
    void getInfo()
    { // this Cat class has Animal's variables because inherits it
        cout << "Name : " << name << endl;
        cout << "Kind : " << kind << endl;
        cout << "Age : " << age << endl;
    }
};

#endif