// create an irregualr two-dimensional array of type int.
#include <iostream>

int main()
{
    int numberOfRows = 5;

    int length[5] = {6, 3, 4, 2, 7};

    int ** irregularArray = new int* [numberOfRows];

    for (int i = 0; i < numberOfRows; ++i) {
        irregularArray[i] = new int [length[i]];
    }

    irregularArray[2][3]  = 5;
    irregularArray[4][6] = irregularArray[2][3] + 2;
    irregularArray[1][1] = 3;

    std::cout << irregularArray[2][3] << std::endl;
    std::cout << irregularArray[4][6] << std::endl;
    std::cout << irregularArray[1][1] << std::endl;

    return 0;
}
