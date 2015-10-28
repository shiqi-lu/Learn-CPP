#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <iostream>
#include <list>

class Component
{
public:
    Component() {}
    virtual ~Component() {}

    virtual void Operation() = 0;

    virtual void Add(Component * pChild) {}
    virtual void Remove(Component * pChild) {}
    virtual Component * GetChild(int nIndex) {return NULL;}
};

class Leaf : public Component
{
public:
    Leaf() {}
    virtual ~Leaf() {}

    virtual void Operation() 
        {std::cout << "Operation by leaf" << std::endl;}
};

class Composite : public Component
{
public:
    Composite() {}
    virtual ~Composite();

    virtual void Operation();

    virtual void Add(Component * pChild);
    virtual void Remove(Component * pChild);
    virtual Component * GetChild(int nIndex);

private:
    std::list<Component *> ListOfComponent_;
};

#endif
