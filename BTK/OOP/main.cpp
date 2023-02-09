#include <iostream>

using namespace std;

class Calculate
{
public:
    int height, width, area;

    void input()
    {
        cout << "Enter height" << endl;
        cin >> height;

        cout << "Enter width" << endl;
        cin >> width;
    }

    void calculate_area()
    {
        area = height * width;
        cout << "Area: " <<  area << endl;
    }
};

class MathSample
{
public:
    int a, b, result = 0;

    void sum()
    {
        this->result = this->a + this->b;
    }

    void print()
    {
        cout << this->result << endl;
    }
};

int main()
{
    MathSample mathSample;
    mathSample.a = 5;
    mathSample.b = 12;

    mathSample.sum();
    mathSample.print();

    Calculate calculate;
    calculate.input();
    calculate.calculate_area();

    return 0;
}