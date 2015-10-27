#include <iostream>
#include "Decorator.h"

Decorator::~Decorator()
{
    delete pComponent_;
    pComponent_ = NULL;
}

void ConcreateComponent::Operation()
{
    std::cout << "Operation of ConcreateComponent" << std::endl;
}

void ConcreateDecorator::Operation()
{
    pComponent_->Operation();
    AddedBehavior();
}

void ConcreateDecorator::AddedBehavior()
{
    std::cout << "AddedBehavior of ConcreateDecorator" << std::endl;
}


