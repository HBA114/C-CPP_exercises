#include <iostream>

int main()
{
    std::string versionText = "";

    switch (__cplusplus)
    {
    case 199711L:
        versionText = "98";
        break;
    case 201103L:
        versionText = "11";
        break;
    case 201402L:
        versionText = "14";
        break;
    case 201703L:
        versionText = "17";
        break;
    case 202002L:
        versionText = "20";
        break;
    case 202101L:
        versionText = "23";
        break;
    default:
        std::cout << "pre standard.";
        break;
    }

    std::cout << "C++ " << versionText << std::endl;
    return 0;
}
