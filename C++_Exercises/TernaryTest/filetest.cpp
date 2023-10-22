#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ostream &myout = (argc > 1 ? *(new ofstream(argv[1])) : cout);

    myout << "Printing text to somewhere." << endl;

    return 0;
}
