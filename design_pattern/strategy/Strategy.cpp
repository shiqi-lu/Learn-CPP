#include <iostream>
#include "Strategy.h"

Context::Context(Strategy * pStrategy) : pStrategy_(pStrategy)
{
}

Context::~Context()
{
    delete pStrategy_;
    pStrategy_ = NULL;
}

void Context::ContextInterface()
{
    if (NULL != pStrategy_) {
        pStrategy_->AlgorithmInterface();
    }
}

void ConcreateStrategyA::AlgorithmInterface()
{
    std::cout << "AlgorithmInterface Implemented by ConcreateStrategyA"
              << std::endl;
}
