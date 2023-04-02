#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void voice() = 0;
};

class Dog : public Animal
{
public:
    void voice()
    {
        cout << "Woof" << endl;
    }
};

class Cat : public Animal
{
public:
    void voice()
    {
        cout << "Meow" << endl;
    }
};

class Duck : public Animal
{
public:
    void voice()
    {
        cout << "Quack" << endl;
    }
};

class Mouse : public Animal
{
    public:
    void voice()
    {
        cout << "Squeak" << endl;
    }
};

void playAllVoices(Animal *animal)
{
    animal->voice();
}

int main()
{
    Dog dog;
    Cat cat;
    Duck duck;
    Mouse mouse;

    playAllVoices(&dog);
    playAllVoices(&cat);
    playAllVoices(&duck);
    playAllVoices(&mouse);

    return 0;
}
