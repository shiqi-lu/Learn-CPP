#include "TemplateMethod.h"

int main()
{
    AbstractClass * pConcreateClass = new ConcreateClass;
    pConcreateClass->TemplateMethod();

    delete pConcreateClass;

    return 0;
}

/*
output:
PrimitiveOperation1 by ConcreateClass
PrimitiveOperation2 by ConcreateClass
*/
