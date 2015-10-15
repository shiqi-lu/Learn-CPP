#include <iostream>

const int defaultSize = 10;

template <typename DataType> class SeqList
{
public:
    SeqList(int size = defaultSize) 
    {
        if (size > 0) {
            maxSize = size;
            elements = new DataType[maxSize];
        }
    }

    ~SeqList()
    {
        delete [] elements;
    }
    bool insertElement(DataType data);
    bool deleteElement(int location);
    DataType getElement(int location);
    bool changeElement(int location, DataType newData);

    int getLength()
    {
        return length;
    }

private:
    DataType * elements;
    int maxSize;
    int length;
};

template <typename DataType>
bool SeqList<DataType>::insertElement(DataType data)
{
    int currentIndex = length;
    if (length >= maxSize) {
        return false;
    } else {
        elements[currentIndex] = data;
        ++length;
        return true;
    }
}

template <typename DataType>
bool SeqList<DataType>::deleteElement(int location)
{
    if (location >= length || location < 0) {
        return false;
    } else {
        for (int i = location; i < length; ++i) {
            elements[i] = elements[i+1];
        }
        --length;
        return true;
    }
}

template <typename DataType>
DataType SeqList<DataType>::getElement(int location)
{
    if (location < 0 || location > length) {
        std::cout << "Invalid parameter" << std::endl;
        return 0;
    } else {
        return elements[location];
    }
}

template <typename DataType>
bool SeqList<DataType>::changeElement(int location, DataType newData)
{
    if (location < 0 || location >= length) {
        return false;
    } else {
        elements[location] = newData;
        return true;
    }
}

int main()
{
    SeqList<int> list(10);
    for (int i = 0; i < 10; ++i) {
        list.insertElement(i * 10);
    }
    for (int i = 0; i < list.getLength(); ++i) {
        std::cout << list.getElement(i) << " ";
    }
    std::cout << std::endl;
    list.deleteElement(3);
    for (int i = 0; i < list.getLength(); ++i) {
        std::cout << list.getElement(i) << " ";
    }
    std::cout << std::endl;
    list.changeElement(5, 44);
    for (int i = 0; i < list.getLength(); ++i) {
        std::cout << list.getElement(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
