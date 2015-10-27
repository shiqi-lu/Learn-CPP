#include "Decorator.h"

int main()
{
    Component * pComponent = new ConcreateComponent();

    Decorator * pDecorator = new ConcreateDecorator(pComponent);

    pDecorator->Operation();

    delete pDecorator;

    return 0;
}

/* output:
Operation of ConcreateComponent
AddedBehavior of ConcreateDecorator
*/
