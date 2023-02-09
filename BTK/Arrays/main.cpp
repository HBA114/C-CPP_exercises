#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int numbers[5]{1, 2, 3, 4, 5};
    int numbers2[5];
    int numbers3[5]{};

    cout << "int numbers[5]{1, 2, 3, 4, 5};" << endl;
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
    {
        cout << numbers[i] << endl;
    }

    cout << endl
         << "int numbers2[5];" << endl;
    for (int i = 0; i < sizeof(numbers2) / sizeof(int); i++)
    {
        cout << numbers2[i] << endl;
    }

    cout << endl
         << "int numbers3[5]{};" << endl;
    for (int i = 0; i < sizeof(numbers3) / sizeof(int); i++)
    {
        cout << numbers3[i] << endl;
    }

    // Address on the ram of first element of array
    cout << endl
         << numbers << endl;
    // Value on the address
    cout << *numbers << endl;
}