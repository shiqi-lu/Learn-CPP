#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <algorithm>

#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

template <typename T>
class arrayList : public linearList<T>
{
public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList() {delete [] element;}
    bool empty() const {return listSize == 0;}
    int size() const {return listSize;}
    T & get(int theIndex) const;
    int indexOf(const T & theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T & theElement);
    void output(std::ostream & out)const;
    int capacity() const {return arrayLength;}

    class iterator;
    iterator begin() { return iterator(element); }
    iterator end() { return iterator(element + listSize); }

    class iterator
    {
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T * pointer;
        typedef T & reference;

        iterator(T * thePosition = 0) {position = thePosition;}

        T & operator*() const { return *position; }
        T * operator->() const { return &*position; }
        iterator & operator++() { ++position; return *this; }
        iterator operator++(int)
        {
            iterator old = *this;
            ++position;
            return old;
        }

        iterator & operator--()
        {
            --position;
            return *this;
        }
        iterator operator--(int)
        {
            iterator old = *this;
            --position;
            return old;
        }

        bool operator!=(const iterator right) const
            { return position != right.position; }
        bool operator==(const iterator right) const
            { return position == right.position; }

    protected:
        T * position;
    };

protected:
    void checkIndex(int theIndex) const;
    T * element;
    int arrayLength;
    int listSize;
};

template <typename T>
arrayList<T>::arrayList(int initialCapacity)
{
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template <typename T>
arrayList<T>::arrayList(const arrayList<T> & theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    std::copy(theList.element, theList.element + listSize, element);
}

template <typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template <typename T>
T & arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

template <typename T>
int arrayList<T>::indexOf(const T & theElement) const
{
    int theIndex = (int) (std::find(element, element + listSize, theElement) - element);

    if (theIndex == listSize) {
        return -1;
    } else {
        return theIndex;
    }
}

template <typename T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    std::copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

template <typename T>
void arrayList<T>::insert(int theIndex, const T & theElement)
{
    if (theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (listSize == arrayLength) {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    std::copy_backward(element + theIndex, element + listSize,
                       element + listSize + 1);

    element[theIndex] = theElement;
    ++listSize;
}

template <typename T>
void arrayList<T>::output(std::ostream & out) const
{
    std::copy(element, element + listSize, std::ostream_iterator<T>(std::cout, " "));
}

template <typename T>
std::ostream & operator<<(std::ostream & out, const arrayList<T> & x)
{
    x.output(out);
    return out;
}

#endif
