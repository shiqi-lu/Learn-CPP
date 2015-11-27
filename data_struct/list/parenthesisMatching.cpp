#include <iostream>
#include <string>
#include "arrayStack.h"

void printMatchedPairs(std::string expr)
{
    arrayStack<int> s;
    int length = (int) expr.size();

    for (int i = 0; i < length; ++i) {
        if (expr.at(i) == '(') {
            s.push(i);
        } else if (expr.at(i) == ')') {
            try {
                std::cout << s.top() << ' ' << i << std::endl;
                s.pop();
            } catch (stackEmpty) {
                std::cout << "No match for right parenthesis at"
                          << i << std::endl;
            }
        }
    }
    
    while (!s.empty()) {
        std::cout << "No match for left parenthesis at "
                  << s.top() << std::endl;
    }
}

int main()
{
    std::string expr;
    std::cout << "Type an expression" << std::endl;
    std::cin >> expr;
    std::cout << "The pairs of matching parentheses in "
              << std::endl << expr << std::endl << " are "
              <<std::endl;

    printMatchedPairs(expr);

    return 0;
}
