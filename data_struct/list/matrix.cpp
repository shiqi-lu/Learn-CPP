#include <iostream>
#include "matrix.h"

int main()
{
    try {
        matrix<int> x(3,2), y, z;
        int i, j;
        for (i = 1; i <= 3; ++i) {
            for (j = 1; j <= 2; ++j) {
                x(i,j) = 2 * i + j;
            }
        }
        std::cout << "Initialized x(i,j) = 2 * i + j" << std::endl;
        std::cout << "x(3,1) = " << x(3,1) << std::endl;
        std::cout << "x is " << std::endl;
        std::cout << x << std::endl;

        y = x;
        std::cout << "Assigned y = x" << std::endl;
        std::cout << "y is" << std::endl;
        std::cout << y << std::endl;

        x += 2;
        std::cout << "x incremented by 2 is " << std::endl;
        std::cout << x << std::endl;

        z = y + x;
        std::cout << "y + x is" << std::endl;
        std::cout << +z << std::endl;

        std::cout << "-(y + x) is " << std::endl;
        std::cout << -z << std::endl;

        matrix<int> w(2,3);
        for (i = 1; i <= 2; ++i) {
            for (j = 1; j <= 3; ++j) {
                w(i,j) = i + j;
            }
        }
        std::cout << "Initialized w(i,j) = i + j" << std::endl;
        std::cout << "w is" << std::endl;
        std::cout << w << std::endl;

        z = y * w;
        std::cout << "y * w is " << std::endl;
        std::cout << z << std::endl;
    } catch (...) {
        std::cerr << "An exception has occurred" << std::endl;
    }


    return 0;
}
/*
Initialized x(i,j) = 2 * i + j
x(3,1) = 7
x is
3 4
5 6
7 8

Assigned y = x
y is
3 4
5 6
7 8

x incremented by 2 is
5 6
7 8
9 10

y + x is
8 10
12 14
16 18

-(y + x) is
-8 -10
-12 -14
-16 -18

Initialized w(i,j) = i + j
w is
2 3 4
3 4 5

y * w is
18 25 32
28 39 50
38 53 68
*/
