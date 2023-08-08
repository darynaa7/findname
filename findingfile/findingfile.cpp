#include "FindFile.h"
#include <iostream>

int main()
{
    
#ifdef _WIN32
    std::string root = "C:\\";
#else
    std::string root = "/";
#endif 

    std::string name;
    std::cout << " input the name: ";
    std::cin >> name;
    Start(name, root);
    std::cin.ignore();
    std::cin.get();
}
