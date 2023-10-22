#include "operations.h"

int main()
{
    string text;
    string temp = "";
    int count = 0;

    while (true)
    {
        system("clear");
        cout << "Enter a text for convert binary..." << endl;

        if (count != 0)
            getchar();

        getline(cin, text);

        char_to_ascii(text);

        cout << endl
             << "For re-enter a text enter 1, for exit enter 0" << endl;

        cin >> temp;

        if (temp == "0")
            break;

        count++;
    }
}
