#include <iostream>

using namespace std;

void test(int *array)
{
    // writes address on the ram
    cout << array << endl;

    // writes elements of array
    for (int i = 0; i < 3; i++)
    {
        cout << array[i] << endl;
    }
}

void test_char(char *array)
{
    // writes char array like string
    cout << array << endl;
}

int main()
{
    int a[]{1, 2, 3};
    test(a);

    char b[] = {"Hasan"};
    test_char(b);

    return 0;
}