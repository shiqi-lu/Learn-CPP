#ifndef STRATEGY_H_
#define STRATEGY_H_

class Strategy;

class Context
{
public:
    Context(Strategy * pStrategy);
    ~Context();

    void ContextInterface();

private:
    Strategy * pStrategy_;
};

class Strategy
{
public:
    virtual ~Strategy() {}

    virtual void AlgorithmInterface() = 0;
};

class ConcreateStrategyA : public Strategy
{
public:
    virtual ~ConcreateStrategyA() {}

    virtual void AlgorithmInterface();
};

#endif
