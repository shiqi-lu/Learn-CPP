#include <deque>
#include <string>
#include <stdexcept>
#include "stack1.hpp"

template<>
class Stack<std::string>
{
public:
    void push(std::string const &);
    void pop();
    std::string top() const;
    bool empty() const { return elems.empty(); }
    
private:
    std::deque<std::string> elems;
};

void Stack<std::string>::push(std::string const & elem)
{
    elems.push_back(elem);
}

void Stack<std::string>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>pop(): empty stack");
    }
    elems.pop_back();
}

std::string Stack<std::string>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>::top(): empty stack");
    }
    return elems.back();
}
