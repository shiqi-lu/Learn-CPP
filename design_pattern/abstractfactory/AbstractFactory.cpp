#include <iostream>
#include "AbstractFactory.h"

ConcreateProductA1::ConcreateProductA1()
{
    std::cout << "construction of ConcreateProductA1" << std::endl;
}

ConcreateProductA1::~ConcreateProductA1()
{
    std::cout << "destruction of ConcreateProductA1" << std::endl;
}

ConcreateProductA2::ConcreateProductA2()
{
    std::cout << "construction of ConcreateProductA2" << std::endl;
}

ConcreateProductA2::~ConcreateProductA2()
{
    std::cout << "destruction of ConcreateProductA2" << std::endl;
}

ConcreateProductB1::ConcreateProductB1()
{
    std::cout << "construction of ConcreateProductB1" << std::endl;
}

ConcreateProductB1::~ConcreateProductB1()
{
    std::cout << "destruction of ConcreateProductB1" << std::endl;
}

ConcreateProductB2::ConcreateProductB2()
{
    std::cout << "construction of ConcreateProductB2" << std::endl;
}

ConcreateProductB2::~ConcreateProductB2()
{
    std::cout << "destruction of ConcreateProductB2" << std::endl;
}

ConcreateFactory1::ConcreateFactory1()
{
    std::cout << "construction of ConcreateFactory1" << std::endl;
}

ConcreateFactory1::~ConcreateFactory1()
{
    std::cout << "destruction of ConcreateFactory1" << std::endl;
}

AbstractProductA * ConcreateFactory1::CreateProductA()
{
    return new ConcreateProductA1();
}

AbstractProductB * ConcreateFactory1::CreateProductB()
{
    return new ConcreateProductB1();
}

ConcreateFactory2::ConcreateFactory2()
{
    std::cout << "construction of ConcreateFactory2" << std::endl;
}

ConcreateFactory2::~ConcreateFactory2()
{
    std::cout << "destruction of ConcreateFactory2" << std::endl;
}

AbstractProductA * ConcreateFactory2::CreateProductA()
{
    return new ConcreateProductA2();
}

AbstractProductB * ConcreateFactory2::CreateProductB()
{
    return new ConcreateProductB2();
}


