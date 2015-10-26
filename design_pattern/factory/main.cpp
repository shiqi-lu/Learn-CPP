#include <stdlib.h>
#include "Factory.h"

int main()
{
    Creator * p = new ConcreateCreator();
    p->AnOperation();

    delete p;

    return 0;
}

/*
output:
[root@TraumLou factory]# g++ Factory.cpp main.cpp && ./a.out
construction of ConcreateCreator
construction of ConcreateProduct
an operation of product
destruction of ConcreateCreator
*/
