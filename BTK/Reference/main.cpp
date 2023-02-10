#include <iostream>

using namespace std;

int main()
{
    int number = 10;
    int &numberRef = number;    // referencing to number

    cout << "number: " << number << endl;
    cout << "numberRef: " << numberRef << endl;

    numberRef = 20;     // changes apply on number

    cout << "number: " << number << endl;
    cout << "numberRef: " << numberRef << endl;

    int number2 = 10;
    int number3 = number2;  // creating new int value

    cout << "number2: " << number2 << endl;
    cout << "number3: " << number3 << endl;

    number3 = 5;        // changes not apply to number2

    cout << "number2: " << number2 << endl;
    cout << "number3: " << number3 << endl;

    return 0;
}