#include <iostream> // importing libraries
#include <string>
#include "operations.h"

// using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

int main()
{
    string text;
    int decision = 1;
    string temp = "";
    int count = 0;
    while (decision)
    {
        cout << "Enter a text for convert binary..." << endl;
        if (count != 0)
            getchar();
        getline(cin, text);
        char_to_ascii(text);
        do
        {
            cout << endl
                 << "For re-enter a text enter 1, for exit enter 0" << endl;
            cin >> temp;
            if (int(temp[0]) == 48)
                decision = 0;
            if (int(temp[0]) == 49)
                decision = 1;
        } while (temp.size() != 1 || (int(temp[0]) != 48 && int(temp[0]) != 49)); // ( decision != 0 && decision != 1);
        count++;
    }
}