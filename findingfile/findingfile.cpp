#include "FindFile.h"
#include <iostream>

int main()
{
#ifdef _WIN32
    std::string root = "C:\\";
#else
    std::string root = "/";
#endif 

    
    FindFile find(root, name);
    find.Start();
    std::cin.ignore();
    std::cin.get();
}
