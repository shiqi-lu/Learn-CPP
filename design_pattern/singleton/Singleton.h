#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton
{
public:
    Singleton() {}
    ~Singleton() {}

    static Singleton * GetInstancePtr();
    static Singleton GetInstance();

    void Test();

private:
    static Singleton * pStatic_;
};

#endif
