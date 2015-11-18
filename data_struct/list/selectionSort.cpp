// selection sort
#include <iostream>
#include <algorithm>
#include <iterator>
#include "indexOfMax.h"

template <typename T>
void selectionSort(T a[], int n)
{
    for (int size = n; size > 1; --size) {
        int j = indexOfMax(a, size);
        std::swap(a[j], a[size - 1]);
    }
}

int main()
{
    int a[10] = {3, 2, 4, 1, 6, 9, 8, 7, 5, 0};

    std::cout << "a[0:9] = ";
    std::copy(a, a + 10, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    selectionSort(a, 10);

    std::cout << "After the sort, a[0:9] = ";
    std::copy(a, a + 10, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

/*
a[0:9] = 3 2 4 1 6 9 8 7 5 0
After the sort, a[0:9] = 0 1 2 3 4 5 6 7 8 9
*/
