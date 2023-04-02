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

    virtual void sound() = 0;
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

    void fire()
    {
        Weapon::fire();
        cout << "Fire from AK47 fire Method" << endl;
    }

    void sound()
    {
        cout << "Rataatatata!" << endl;
    }
};

class SarsilmazSar9 : public Weapon
{
public:
    void sound()
    {
        cout << "Bam Bam Bam" << endl;
    }
};

class AWP : public Weapon
{
};

class M1 : public Weapon
{
public:
    bool hasScope;
    bool hasStrap;
};

class M1Silver : public M1
{
    void sound()
    {
        // must override
    }
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

void fireSound(Weapon *weapon)
{
    weapon->sound();
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

    fireSound(&ak47);
    fireSound(&sar9);

    M1Silver m1Silver;
    m1Silver.hasStrap = true;

    return 0;
}
