#ifndef MATRIX_H_
#define MATRIX_H_

#include "myExceptions.h"

template <typename T>
class matrix
{
public:
    matrix(int theRows = 0, int theColumns = 0);
    matrix(const matrix<T>&);
    ~matrix() { delete [] element; }
    int rows() const { return theColumns; }
    T & operator()(int i, int j) const;
    matrix<T> & operator=(const matrix<T>&);
    matrix<T> operator+() const;
    matrix<T> operator+(const matrix<T>&) const;
    matrix<T> operator-() const;
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T> operator*(const matrix<T>&) const;
    matrix<T>& operator+=(const T&);
    friend std::ostream & operator<<(std::ostream&, const matrix<T>&);

private:
    int theRows, theColumns;
    T * element;
};

template <typename T>
matrix<T>::matrix(int theRows, int theColumns)
{
    if (theRows < 0 || theColumns < 0) {
        throw illegalParameterValue("Rows and columns must be >= 0");
    }
    if ((theRows == 0 || theColumns < 0)
            && (theRows != 0 || theColumns != 0)) {
        throw illegalParameterValue
            ("Either both or neither rows and columns should be zero");
    }

    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T [theRows * theColumns];
}

template <typename T>
matrix<T>::matrix(const matrix<T> & m)
{
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T [theRows * theColumns];

    std::copy(m.element, m.element + theRows * theColumns, element);
}

template <typename T>
matrix<T> & matrix<T>::operator=(const matrix<T> & m)
{
    if (this != &m) {
        delete [] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T [theRows * theColumns];
        std::copy(m.element, 
                  m.element + theRows * theColumns,
                  element);
    }
    return *this;
}

template <typename T>
T & matrix<T>::operator()(int i, int j) const
{
    if (i < 1 || i > theRows
        || j < 1 || j > theColumns) {
        throw matrixIndexOutOfBounds();
    }
    return element[(i-1) * theColumns + j - 1];
}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T> & m) const
{
    if (theRows != m.theRows
        || theColumns != m.theColumns) {
        throw matrixSizeMismatch();
    }
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; ++i) {
        w.element[i] = element[i] + m.element[i];
    }

    return w;
}

template <typename T>
matrix<T> matrix<T>::operator+() const
{
    matrix<T> w(theRows, theColumns);
    std::copy(element, element + theRows * theColumns, w.element);
    return w;
}

template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T> & m) const
{
    if (theRows != m.theRows
        || theColumns != m.theColumns) {
        throw matrixSizeMismatch();
    }
    matrix<T> w (theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; ++i) {
        w.element[i] = element[i] - m.element[i];
    }
    return w;
}

template <typename T>
matrix<T> matrix<T>::operator-() const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; ++i) {
        w.element[i] = -element[i];
    }
    return w;
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T> & m) const
{
    if (theColumns != m.theRows) {
        throw matrixSizeMismatch();
    }

    matrix<T> w(theRows, m.theColumns);

    int ct = 0, cm = 0, cw = 0;

    for (int i = 1; i <= theRows; ++i) {
        for (int j = 1; j <= m.theColumns; ++j) {
            T sum = element[ct] * m.element[cm];

            for (int k = 2; k <= theColumns; ++k) {
                ++ct;
                cm += m.theColumns;
                sum += element[ct] * m.element[cm];
            }
            w.element[cw++] = sum;

            ct -= theColumns - 1;
            cm = j;
        }
        ct += theColumns;
        cm = 0;
    }

    return w;
}

template <typename T>
matrix<T> & matrix<T>::operator+=(const T & x)
{
    for (int i = 0; i < theRows * theColumns; ++i) {
        element[i] += x;
    }
    return * this;
}

template <typename T>
std::ostream & operator<<(std::ostream & out, const matrix<T> & m)
{
    int k = 0;
    for (int i = 0; i < m.theRows; ++i) {
        for (int j =  0; j < m.theColumns; ++j) {
            out << m.element[++k] << " ";
        }
        out << std::endl;
    }
    return out;
}

std::ostream & operator << (std::ostream & out, const matrix<int> & m)
{
    int k = 0;
    for (int i = 0; i < m.theRows; ++i) {
        for (int j = 0; j < m.theColumns; ++j) {
            out << m.element[k++] << " ";
        }
        out << std::endl;
    }
    return out;
}

#endif
