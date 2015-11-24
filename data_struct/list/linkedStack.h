#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include "stack.h"
#include "chainNode.h"
#include "myExceptions.h"
#include <sstream>

template <typename T>
class linkedStack : public stack<T>
{
public:
    linkedStack(int initialCapacity = 10)
        { stackTop = NULL; stackSize = 0; }
    ~linkedStack();
    bool empty() const
        { return stackSize == 0; }
    int size() const { return stackSize; }
    T & top()
    {
        if (stackSize == 0) {
            throw stackEmpty();
        }
        return stackTop->element;
    }
    void pop();
    void push(const T & theElement)
    {
        stackTop = new chainNode<T>(theElement, stackTop);
        ++stackSize;
    }
private:
    chainNode<T> * stackTop;
    int stackSize;
};

template <typename T>
linkedStack<T>::~linkedStack()
{
    while (stackTop != NULL) {
        chainNode<T> * nextNode = stackTop->next;
        delete stackTop;
        stackTop = nextNode;
    }
}

template <typename T>
void linkedStack<T>::pop()
{
    if (stackSize == 0) {
        throw stackEmpty();
    }
    chainNode<T> * nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
    --stackSize;
}

#endif
