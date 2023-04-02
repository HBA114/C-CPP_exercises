#include <iostream>

using namespace std;

class Weapon
{
private:
    int value = 10;

public:
    const int constValue = 10;
    int get() const
    {
        // value = 100; //! Cant change any member of class in this method
        return value;
    }

    const int *get2()
    {
        return &value;
    }

    int const *get3()
    {
        return &value;
    }
};

int main()
{
    const int a = 10;
    // a = 100; //! Error: Cant change const value

    Weapon weapon;
    // weapon.constValue = 100; //! Error: Cant change const value
    cout << weapon.get() << endl;

    const int *test = weapon.get2(); //! const int* can be assign to const int* variable

    cout << *(weapon.get2()) << endl;
    // *(weapon.get2()) = 100;  //! Cant change const

    // int *a = weapon.get3(); //! "const int *" cannot be used to initialize an entity of type "int *"

    return 0;
}
