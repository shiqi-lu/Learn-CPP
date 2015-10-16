#ifndef CHANGELENGTH1D_H_
#define CHANGELENGTH1D_H_

#include "myExceptions.h"

template <typename T>
void changeLength1D(T *& a, int oldLength, int newLength)
{
    if (newLength < 0) {
        throw illegalParameterValue("new length must be >= 0");
    }

    T * temp = new T[newLength];
    int number = std::min(oldLength, newLength);
    std::copy(a, a + number, temp);
    delete [] a;
    a = temp;
}

#endif
