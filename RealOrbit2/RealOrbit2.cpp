
#include <iostream>

#include "rendering/MeshLibrary.h"


int main()
{
    MeshLibrary ml;

    int a = ml.m_NameHandleLookup["FirstKey"] + ml.m_NameHandleLookup["SecondKey"];
    int b = ml.m_NameHandleLookup["FirstKey"] + ml.m_NameHandleLookup["asd"];

    std::cout << ml.m_NameHandleLookup["FirstKey"] << "\n";
    std::cout << ml.m_NameHandleLookup["SecondKey"] << "\n";
    std::cout << ml.m_NameHandleLookup["ThirdKey"] << "\n";
    std::cout << ml.m_NameHandleLookup["asd"] << "\n";
    std::cout << ml.m_NameHandleLookup["eqw"] << "\n";

    ml.m_NameHandleLookup["SecondKey"] = 20;
    std::cout << ml.m_NameHandleLookup["SecondKey"] << "\n";

    std::cout << "Hello World!\n";
}
