class AbstractClass
{
public:
    AbstractClass() {}
    virtual ~AbstractClass() {}

    void TemplateMethod();

protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

class ConcreateClass : public AbstractClass
{
public:
    ConcreateClass() {}
    virtual ~ConcreateClass() {}

protected:
    virtual void PrimitiveOperation1();
    virtual void PrimitiveOperation2();
};
