#include "FindFile.h"
#include <iostream>

int main()
{
    std::string root = "";
    std::string name = "";
    std::cout << " input the root: ";
    std::cin >> root;
    std::cout << " input the name: ";
    std::cin >> name;
    FindFile find(root, name);
    find.Start();
    std::cin.get();
}
