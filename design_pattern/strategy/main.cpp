#include "Strategy.h"

int main()
{
    Strategy * pStrategy = new ConcreateStrategyA();
    Context * pContext = new Context(pStrategy);

    pContext->ContextInterface();

    delete pContext;

    return 0;
}

/*
output:
AlgorithmInterface Implemented by ConcreateStrategyA
*/
