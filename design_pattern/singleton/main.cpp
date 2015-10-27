#include "Singleton.h"

int main()
{
    Singleton::GetInstancePtr()->Test();

    Singleton::GetInstance().Test();

    return 0;
}
