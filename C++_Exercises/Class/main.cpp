#include "cat.h"

int main()
{
    Cat myCat, yourCat;               // Create 2 different Cat object.
    myCat.EnterName("My_Cat's_Name"); // Assign a name to first Cat object.
    yourCat.name = "Your_Cat's_Name"; // Assign a name to second Cat object.
    myCat.EnterKind("Domestic Cat");  // Enter the kind of cat with EnterKind method.
    yourCat.kind = "Scottish Fold";   // Enter the kind of cat with kind variable directly.
    myCat.EnterAge(4);                // Enter the age of cat with EnterAge method.
    yourCat.age = 3;                  // Enter the age of cat with age varible directly.

    // in this 2 lines i called a method that Cat have and give Info about Cat object
    myCat.GetInfo();
    yourCat.GetInfo();
    return 0;
}
