// bubble sort
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
void bubble(T a[], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i+1]) {
            std::swap(a[i], a[i+1]);
        }
    }
}

template <typename T>
void bubbleSort(T a[], int n)
{
    for (int i = n; i > 1; --i) {
        bubble(a, i);
    }
}

int main()
{
    int a[10] = {10,7,8,9,4, 2, 3, 6, 5,1};

    // output the elements
    std::cout << "a[0:9] = ";
    std::copy(a, a+10, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // sort
    bubbleSort(a,10);

    // output the sorted sequence
    std::cout << "After the sort, a[0:9] = ";
    std::copy(a, a+10, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
