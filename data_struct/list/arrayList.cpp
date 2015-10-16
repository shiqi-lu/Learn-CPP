#include <iostream>
#include "linearList.h"
#include "arrayList.h"

int main()
{
    linearList<double> * x = new arrayList<double>(20);
    arrayList<int> y(2), z;

    std::cout << "Capacity of x, y and z = "
              << ((arrayList<double> *) x)->capacity() << ", "
              << y.capacity() << ", "
              << z.capacity() << std::endl;

    std::cout << "Initial size of x, y, and z = "
              << x->size() << ", "
              << y.size() << ", "
              << z.size() << std::endl;

    if (x->empty()) {
        std::cout << "x is empty" << std::endl;
    } else {
        std::cout << "x is not empty" << std::endl;
    }

    if (y.empty()) {
        std::cout << "y is empty" << std::endl;
    } else {
        std::cout << "y is not empty" << std::endl;
    }

    y.insert(0, 2);
    y.insert(1, 6);
    y.insert(0, 1);
    y.insert(2, 4);
    y.insert(3, 5);
    y.insert(2, 3);
    std::cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << std::endl;
    std::cout << "Size of y = " << y.size() << std::endl;
    std::cout << "Capacity of y = " << y.capacity() << std::endl;
    if (y.empty()) {
        std::cout << "y is empty" << std::endl;
    } else {
        y.output(std::cout);
    }
    std::cout << std::endl << "Testing overloaded <<" << std::endl;
    std::cout << y << std::endl;

    int index = y.indexOf(4);
    if (index < 0) {
        std::cout << "7 not found" << std::endl;
    } else {
        std::cout << "The index of 4 is " << index << std::endl;
    }

    std::cout << "Element with index 0 is " << y.get(0) << std::endl;
    std::cout << "Element with index 3 is " << y.get(3) << std::endl;

    y.erase(1);
    std::cout << "Element 1 erased" << std::endl;
    std::cout << "The list is " << y << std::endl;
    y.erase(2);
    std::cout << "Element 2 erased" << std::endl;
    std::cout << "The list is " << y << std::endl;

    std::cout << "Size of y = " << y.size() << std::endl;
    std::cout << "Capacity of y = " << y.capacity() << std::endl;

    if (y.empty()) {
        std::cout << "y is empty" << std::endl;
    } else {
        std::cout << "y is not empty" << std::endl;
    }

    try {
        y.insert(-3, 0);
    } catch (illegalIndex e) {
        std::cout << "Illegal index exception" << std::endl;
        std::cout << "Insert index must be between 0 and list size" << std::endl;
        e.outputMessage();
    }

    arrayList<int> w(y);
    y.erase(0);
    y.erase(0);
    std::cout << "w should be old y, new y has first 2 elements removed" << std::endl;
    std::cout << "w is " << w << std::endl;
    std::cout << "y is " << y << std::endl;



    return 0;
}

/* output:
Capacity of x, y and z = 20, 2, 10
Initial size of x, y, and z = 0, 0, 0
x is empty
y is empty
Inserted 6 integers, list y should be 1 2 3 4 5 6
Size of y = 6
Capacity of y = 8
1 2 3 4 5 6
Testing overloaded <<
1 2 3 4 5 6
The index of 4 is 3
Element with index 0 is 1
Element with index 3 is 4
Element 1 erased
The list is 1 3 4 5 6
Element 2 erased
The list is 1 3 5 6
Size of y = 4
Capacity of y = 8
y is not empty
Illegal index exception
Insert index must be between 0 and list size
index = -3 size = 4
w should be old y, new y has first 2 elements removed
w is 1 3 5 6
y is 5 6
*/
