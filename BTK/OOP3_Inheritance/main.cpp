#include <iostream>

using namespace std;

class Weapon
{
protected:
    int serialNumber;

public:
    string name;
    int ammoCapacity;
    string color;

    Weapon()
    {
        cout << "Weapon (" << name << ")Created!" << endl;
    }

    ~Weapon()
    {
        cout << "Weapon (" << name << ") Deconstructor!" << endl;
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
        serialNumber = 10; // can assign protected in class scope
    }

    ~AK47()
    {
        cout << "AK47 Deconstructor!" << endl;
    }
};

class SarsilmazSar9 : public Weapon
{
};

class AWP : public Weapon
{
};

void test(AK47 &ak47)
{
    ak47.name = "test123";
}

void testPtr(AK47 *ak47)
{
    ak47->name = "test123PTR";
}

void testWeapon(Weapon &weapon) // works with all weapon that inherits weapon class
{
    weapon.name = "WeaponTest";
}

int main()
{
    AK47 ak47;
    ak47.name = "AK47";
    ak47.ammoCapacity = 30;
    ak47.color = "Wood";
    // ak47.serialNumber = 10;  // cant assign protected out of class scope
    ak47.fire();

    SarsilmazSar9 sar9;
    sar9.name = "Sarsilmaz Sar 9 Pistol";
    sar9.ammoCapacity = 15;
    sar9.color = "Black";
    sar9.fire();
    cout << "AK47 Created!" << endl;

    AK47 ak_47;
    ak_47.name = "AK47_test";
    AK47 *ak47ptr = &ak_47;
    ak47ptr->name = "AK_Test_Ptr";
    ak47ptr->ammoCapacity = 40;
    ak47ptr->fire();

    AK47 &ak47Ref = ak_47;
    ak47Ref.name = "AK_Test_Ref";
    ak47Ref.ammoCapacity = 25;
    ak47Ref.fire();

    test(ak47);
    ak47.fire();

    test(ak47Ref);
    ak47Ref.fire();

    testPtr(&ak47);
    ak47.fire();

    testPtr(ak47ptr);
    ak47ptr->fire();

    testWeapon(ak47);
    ak47.fire();

    return 0;
}