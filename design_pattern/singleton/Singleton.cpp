#include <iostream>
#include "Singleton.h"

Singleton * Singleton::pStatic_ = NULL;

Singleton * Singleton::GetInstancePtr()
{
    if (NULL == pStatic_) {
        pStatic_ = new Singleton();
    }

    return pStatic_;
}

Singleton Singleton::GetInstance()
{
    return * GetInstancePtr();
}

void Singleton::Test()
{
    std::cout << "Test" << std::endl;
}
