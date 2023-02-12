#include <iostream>

using namespace std;

void test(int array[3])
{
    cout << array << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << array[i] << endl;
    }
}

int main()
{
    // Dynamic Array: Can change element count on runtime
    // Static Array: Can't change element count on runtime
    int array[2][2]{{1, 2}, {3, 4}};

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        for (int j = 0; j < sizeof(array[i]) / sizeof(array[0][0]); j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    int array2[2][2][2][2]{
        {{{1, 2},
          {3, 4}},
         {{5, 6},
          {7, 8}}},
        {{{9, 10},
          {11, 12}},
         {{13, 14},
          {15, 16}}}};

    cout << sizeof(array2) << endl;
    cout << sizeof(array2[0]) << endl;
    cout << sizeof(array2[0][0]) << endl;
    cout << sizeof(array2[0][0][0]) << endl;
    cout << sizeof(array2[0][0][0][0]) << endl
         << endl;

    for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++)
    {
        for (int j = 0; j < sizeof(array2[i]) / sizeof(array2[0][0]); j++)
        {
            for (int k = 0; k < sizeof(array2[i][j]) / sizeof(array2[0][0][0]); k++)
            {
                for (int l = 0; l < sizeof(array2[i][j][k]) / sizeof(array2[0][0][0][0]); l++)
                {
                    cout << "array2 [" << i << "] [" << j << "] [" << k << "] [" << l << "] : ";
                    cout << array2[i][j][k][l] << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }

    int array3[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < sizeof(array3) / (sizeof(array3[0])); i++)
    {
        for (int j = 0; j < sizeof(array3[i]) / sizeof(array3[0][0]); j++)
        {
            cout << array3[i][j] << "\t";
        }
        cout << endl;
    }

    const int number = 5;

    int array4[number][number];

    // Arrays are reference type
    int a_array[3]{1, 2, 3};
    cout << a_array << endl;
    test(a_array);

    return 0;
}