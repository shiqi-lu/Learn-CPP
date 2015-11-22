#ifndef TRIDIAGONAL_H_
#define TRIDIAGONAL_H_

#include "myExceptions.h"

template <typename T>
class tridiagonalMatrix
{
public:
    tridiagonalMatrix(int theN = 10);
    ~tridiagonalMatrix() { delete [] element; }
    T get(int, int) const;
    void set(int, int, const T &);
private:
    int n;
    T * element;
};

template <typename T>
tridiagonalMatrix<T>::tridiagonalMatrix(int theN)
{
    if (theN < 1) {
        throw illegalParameterValue("Matrix size must be > 0");
    }

    n = theN;
    element = new T [3 * n - 2];
}

template <typename T>
T tridiagonalMatrix<T>::get(int i, int j) const
{
    if (i < 1 || j < 1 || i > n || j > n) {
        throw matrixIndexOutOfBounds();
    }

    switch (i - j)
    {
    case 1:
        return element[i - 2];
    case 0:
        return element[n + i - 2];
    case -1:
        return element[2 * n + i - 2];
    default:
        return 0;
    }
}

template <typename T>
void tridiagonalMatrix<T>::set(int i, int j, const T & newValue)
{
    if (i < 1 || j < 1 || i > n || j > n) {
        throw matrixIndexOutOfBounds();
    }

    switch (i - j)
    {
    case 1:
        element[i - 2] = newValue;
        break;
    case 0:
        element[n + i - 2] = newValue;
        break;
    case -1:
        element[2 * n + i - 2] = newValue;
        break;
    default:
        if (newValue != 0) {
            throw illegalParameterValue
                ("non-tridiagonal elements must be zero");
        }
    }
}

#endif
