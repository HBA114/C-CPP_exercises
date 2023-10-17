#ifndef cat
#define cat
#include "animal.h"

class Cat : public Animal
{
    // if you forget this access modifier you can not run main.cpp
public:
    // this Cat class has Animal's variables because inherits it
    void GetInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Kind : " << kind << endl;
        cout << "Age : " << age << endl;
    }
};

#endif
