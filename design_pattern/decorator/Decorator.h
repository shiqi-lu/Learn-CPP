#ifndef DECORATOR_H_
#define DECORATOR_H_

class Component
{
public:
    Component() {}
    virtual ~Component() {}

    virtual void Operation() = 0;
};

class Decorator : public Component
{
public:
    Decorator(Component * pComponent) :
        pComponent_(pComponent) {}
    virtual ~Decorator();

protected:
    Component * pComponent_;
};

class ConcreateComponent : public Component
{
public:
    ConcreateComponent() {}
    virtual ~ConcreateComponent() {}

    virtual void Operation();
};

class ConcreateDecorator : public Decorator
{
public:
    ConcreateDecorator(Component * pComponent)
        : Decorator(pComponent) {}
    virtual void Operation();

private:
    void AddedBehavior();
};

#endif
