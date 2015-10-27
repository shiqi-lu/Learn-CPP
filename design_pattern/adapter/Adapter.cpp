#include <iostream>
#include "Adapter.h"

void Adaptee::SpecialRequest()
{
    std::cout << "SpecialRequest of Adaptee" << std::endl;
}

Adapter::Adapter(Adaptee * pAdaptee) : pAdaptee_(pAdaptee)
{
}

Adapter::~Adapter()
{
    delete pAdaptee_;
    pAdaptee_ = NULL;
}

void Adapter::Request()
{
    std::cout << "Request of Adapter" << std::endl;

    pAdaptee_->SpecialRequest();
}
