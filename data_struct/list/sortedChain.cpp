#include <iostream>
#include "sortedChain.h"

int main()
{
    sortedChain<int, int> z;
    
    z.insert(std::make_pair(2, 10));
    z.insert(std::make_pair(10, 50));
    z.insert(std::make_pair(6, 30));
    z.insert(std::make_pair(8, 40));
    z.insert(std::make_pair(1, 5));
    z.insert(std::make_pair(12, 60));

    std::cout << "The chain is " << z << std::endl;
    std::cout << "Its size is " << z.size() << std::endl;

    std::cout << "Element assocaisted with 1 is " 
              << z.find(1)->second << std::endl;
    std::cout << "Element assocaisted with 6 is " 
              << z.find(6)->second << std::endl;
    std::cout << "Element assocaisted with 12 is " 
              << z.find(12)->second << std::endl;

    z.erase(1);
    z.erase(2);
    z.erase(6);
    z.erase(12);

    std::cout << "Deleted 1, 2, 6, 12" << std::endl;
    std::cout << "The chain is " << z << std::endl;
    std::cout << "Its size is " << z.size() << std::endl;

    return 0;
}

/*
The chain is 1 5 2 10 6 30 8 40 10 50 12 60
Its size is 6
Element assocaisted with 1 is 5
Element assocaisted with 6 is 30
Element assocaisted with 12 is 60
Deleted 1, 2, 6, 12
The chain is 8 40 10 50
Its size is 2
*/
