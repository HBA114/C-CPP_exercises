#ifndef animal
#define animal
#include <iostream>
#include <string>

using namespace std;

class Animal
{                // Animal class definition
public:          // Access modifier
    string name; // Animal's name declaration
    string kind; // Animal's kind declaration
    int age;     // Animal's age declaration

    void EnterName(string name)
    {
        this->name = name;
    }

    void EnterKind(string kind)
    {
        this->kind = kind;
    }

    void EnterAge(int age)
    {
        this->age = age;
    }
};

#endif
