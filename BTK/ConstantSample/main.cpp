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
};

int main()
{
    const int a = 10;
    // a = 100; //! Error: Cant change const value

    Weapon weapon;
    // weapon.constValue = 100; //! Error: Cant change const value
    cout << weapon.get() << endl;

    return 0;
}
