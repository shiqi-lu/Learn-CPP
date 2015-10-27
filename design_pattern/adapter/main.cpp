#include "Adapter.h"

int main()
{
    Adaptee * pAdaptee = new Adaptee;
    Target * pTarget = new Adapter(pAdaptee);
    pTarget->Request();

    delete pTarget;

    return 0;
}

/* 
output:
Request of Adapter
SpecialRequest of Adaptee
*/
