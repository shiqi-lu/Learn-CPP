#include "AbstractFactory.h"

int main()
{
    ConcreateFactory1 * pFactory1 = new ConcreateFactory1;
    AbstractProductA * pProductA = pFactory1->CreateProductA();

    ConcreateFactory2 * pFactory2 = new ConcreateFactory2;
    AbstractProductB * pProductB = pFactory2->CreateProductB();

    delete pFactory1;
    delete pProductA;
    delete pFactory2;
    delete pProductB;

    return 0;
}

/* output:
[root@TraumLou abstractfactory]# g++ AbstractFactory.cpp main.cpp
[root@TraumLou abstractfactory]# ./a.out
construction of ConcreateFactory1
construction of ConcreateProductA1
construction of ConcreateFactory2
construction of ConcreateProductB2
destruction of ConcreateFactory1
destruction of ConcreateProductA1
destruction of ConcreateFactory2
destruction of ConcreateProductB2
*/
