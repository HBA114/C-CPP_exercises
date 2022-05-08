#include <iostream>
#include "animal.h"
#include "cat.h"

int main() {
    Cat myCat, yourCat;                 // in this line i create 2 different Cat object.
    myCat.enterName("My_Cat's_Name");   // in this line i gave a name to first Cat object.
    yourCat.name = "Your_Cat's_Name";   // in this line i gave a name to second Cat object.
    myCat.enterKind("Domestic Cat");    // in this line i enter the kind of cat with enterKind method.
    yourCat.kind = "Scottish Fold";     // in this line i enter the kind of cat with kind variable directly.
    myCat.enterAge(4);      // in this line i enter the age of cat with enterAge method.
    yourCat.age = 3;        // in this line i enter the age of cat with age varible directly.

    // in this 2 lines i called a method that Cat have and give Info about Cat object
    myCat.getInfo();
    yourCat.getInfo();
    return 0;
}