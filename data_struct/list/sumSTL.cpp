#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

template <typename T>
T sum(T a[], int n)
{
    T theSum = 0;
    return std::accumulate(a, a+n, theSum);
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};

    std::cout << "a[0:5] = ";
    std::copy(a, a+6, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "sum(a, 0) = " << sum(a, 0) << std::endl;
    std::cout << "sum(a, 1) = " << sum(a, 1) << std::endl;
    std::cout << "sum(a, 6) = " << sum(a, 6) << std::endl;

    return 0;
}

/* output:
a[0:5] = 1 2 3 4 5 6
sum(a, 0) = 0
sum(a, 1) = 1
sum(a, 6) = 21
*/
