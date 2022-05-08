#ifndef animal
#define animal
#include <iostream>
#include <string>

using namespace std;

class Animal {  // Animal class definition
    public:     // access modifier
        string name;    // Animal's name declaration
        string kind;    // Animal's kind declaration
        int age;        // Animal's age declaration

        void enterName(string name) {
            this->name = name;
        }

        void enterKind(string kind) {
            this->kind = kind;
        }

        void enterAge(int age) {
            this->age = age;
        }
};

#endif