#include <iostream>
#include "linkedStack.h"
#include "myExceptions.h"

int main()
{
    linkedStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    std::cout << "Stack should be 1234, bottom to top" << std::endl;

    if (s.empty()) {
        std::cout << "The stack is empty" << std::endl;
    } else {
        std::cout << "The stack is not empty" << std::endl;
    }

    std::cout << "The stack is " << s.size() << std::endl;

    while (!s.empty()) {
        std::cout << "Stack top is " << s.top() << std::endl;
        s.pop();
        std::cout << "Poped top element" << std::endl;
    }

    try {
        s.pop();
    } catch (stackEmpty message) {
        std::cout << "Last pop failed" << std::endl;
        message.outputMessage();
    }

    return 0;
}

/*
Stack should be 1234, bottom to top
The stack is not empty
The stack is 4
Stack top is 4
Poped top element
Stack top is 3
Poped top element
Stack top is 2
Poped top element
Stack top is 1
Poped top element
Last pop failed
Invalid operation on empty stack
*/
