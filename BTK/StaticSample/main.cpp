#include <iostream>

using namespace std;

class Book
{
private:
    int quantity = 10;

public:
};

void test()
{
    // int a = 0;       // output is 1 and 1 because function called 2 times

    static int a = 0;   //* output is 1 and 2 because function called 2 times and value 
                        // of 'a' registered to memory and used from there
    a++;
    cout << a << endl;
}

int main()
{
    test();
    test();
}
