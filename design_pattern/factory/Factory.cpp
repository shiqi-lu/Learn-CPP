#include <iostream>
#include "Factory.h"

ConcreateProduct::ConcreateProduct()
{
    std::cout << "construction of ConcreateProduct" << std::endl;
}

ConcreateProduct::~ConcreateProduct()
{
    std::cout << "destruction of ConcreateProduct" << std::endl;
}

void Creator::AnOperation()
{
    Product * p = FactoryMethod();

    std::cout << "an operation of product" << std::endl;
}

ConcreateCreator::ConcreateCreator()
{
    std::cout << "construction of ConcreateCreator" << std::endl;
}

ConcreateCreator::~ConcreateCreator()
{
    std::cout << "destruction of ConcreateCreator" << std::endl;
}

Product * ConcreateCreator::FactoryMethod()
{
    return new ConcreateProduct();
}

