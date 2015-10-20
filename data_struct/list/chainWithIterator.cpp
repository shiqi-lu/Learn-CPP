#include <iostream>
#include <numeric>
#include "linearList.h"
#include "chainWithIterator.h"

int main()
{
    chain<int> y;
    y.insert(0, 2);
    y.insert(1, 6);
    y.insert(0, 1);
    y.insert(2, 4);
    y.insert(3, 5);
    y.insert(2, 3);
    std::cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << std::endl;
    std::cout << "Size of y = " << y.size() << std::endl;

    std::cout << "Output using forward iterators pre and post ++" << std::endl;
    for (chain<int>::iterator i = y.begin();
         i != y.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    for (chain<int>::iterator i = y.begin();
         i != y.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    std::cout << "Incremented by 1 list is " << y << std::endl;

    int sum = std::accumulate(y.begin(), y.end(), 0);
    std::cout << "The sum of the elements is " << sum << std::endl;

    return 0;
}

/*
output:
Inserted 6 integers, list y should be 1 2 3 4 5 6
Size of y = 6
Output using forward iterators pre and post ++
1 2 3 4 5 6
1 2 3 4 5 6
Incremented by 1 list is 1 2 3 4 5 6
The sum of the elements is 21
*/
