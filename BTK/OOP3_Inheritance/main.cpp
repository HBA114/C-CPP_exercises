#include <iostream>

using namespace std;

class Weapon
{
public:
    string name;
    int ammoCapacity;
    string color;

    Weapon()
    {
        cout << "Weapon Created!" << endl;
    }

    void fire()
    {
        cout << name + ": " << ammoCapacity << " x fire" << endl;
    }
};

class AK47 : public Weapon
{
public:
    bool scope;

    AK47()
    {
        cout << "AK47 Created!" << endl;
    }
};

class SarsilmazSar9 : public Weapon
{
};

class AWP : public Weapon
{
};

int main()
{
    AK47 ak47;
    ak47.name = "AK47";
    ak47.ammoCapacity = 30;
    ak47.color = "Wood";
    ak47.fire();

    SarsilmazSar9 sar9;
    sar9.name = "Sarsilmaz Sar 9 Pistol";
    sar9.ammoCapacity = 15;
    sar9.color = "Black";
    sar9.fire();

    return 0;
}