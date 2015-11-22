//insertion sort
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
void insert(T a[], int n, const T & x)
{
    int i;
    for (i = n-1; i >= 0 && x < a[i]; --i) {
        a[i+1] = a[i];
    }
    a[i+1] = x;
}

template <typename T>
void insertionSort(T a[], int n)
{
    for (int i = 1; i < n; ++i) {
        T t = a[i];
        insert(a, i, t);
    }
}

int main()
{
    int a[10] = {3, 2, 4, 1, 6, 9, 8, 7, 5, 0};
    std::cout << "a[0:9] = ";
    std::copy(a, a+10, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    insertionSort(a, 10);

    std::cout << "After the sort, a[0:9] = ";
    std::copy(a, a+10, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

/*
output:
a[0:9] = 3 2 4 1 6 9 8 7 5 0
After the sort, a[0:9] = 0 1 2 3 4 5 6 7 8 9
*/
