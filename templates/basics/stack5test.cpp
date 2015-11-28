#include <iostream>
#include <string>
#include <cstdlib>
#include "stack5.hpp"

int main()
{
    try {
        Stack<int> intStack;
        Stack<float> floatStack;

        intStack.push(42);
        intStack.push(7);

        floatStack.push(7.7);

        floatStack = intStack;

        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
    } catch (std::exception const & ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

/*
7
42
Exception: Stack<>::pop(): empty stack
*/
