#include <iostream>
#include <string>
#include <cstdlib>
#include "stack1.hpp"

int main()
{
    try {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        stringStack.push("hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    } catch (std::exception const & ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

/*
7
hello
Exception: Stack<>::pop(): empty stack
*/
