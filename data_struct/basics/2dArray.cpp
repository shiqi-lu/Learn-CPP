template <class T>
bool make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{
    try {
        x = new T * [numberOfRows];
        for (int i = 0; i < numberOfRows; ++i) {
            x[i] = new int [numberOfColumns];
        }
        return true;
    } catch (bad_alloc) {
        return false;
    }
}

template <class T>
void make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{
    x = new T * [numberOfRows];

    for (int i = 0; i < numberOfRows; ++i) {
        x[i] = new T [numberOfColumns];
    }
}

template <class T>
void delete2dArray(T ** &x, int numberOfRows)
{
    for (int i = 0; i < numberOfRows; ++i) {
        delete [] x[i];
    }
    delete [] x;
    x = NULL:
}
