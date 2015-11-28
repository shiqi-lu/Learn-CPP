#ifndef STACK_HPP_
#define STACK_HPP_

#include <deque>
#include <stdexcept>

template <typename T>
class Stack
{
public:
    void push(T const & elem) { elems.push_back(elem); }
    void pop();
    T top() const;
    bool empty() const { return elems.empty(); }
    template <typename T2>
    Stack<T> & operator=(Stack<T2> const &);

private:
    std::deque<T> elems;
};

template <typename T>
 template <typename T2>
Stack<T> & Stack<T>::operator=(Stack<T2> const & op2)
{
    if ((void*)this == (void*)&op2) {
        return *this;
    }
    Stack<T2> tmp(op2);
    elems.clear();
    while (!tmp.empty()) {
        elems.push_front(tmp.top());
        tmp.pop();
    }
    return * this;
}

template <typename T>
void Stack<T>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top() : empty stack");
    }
    return elems.back();
}

#endif
