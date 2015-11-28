#include <iostream>

void towersOfHanoi(int n, int x, int y, int z)
{
    if (n > 0) {
        towersOfHanoi(n - 1, x, z, y);
        std::cout << "Move top disk from tower " << x
                  << " to top of tower " << y << std::endl;
        towersOfHanoi(n-1, z, y, x);
    }
}

int main()
{
    std::cout << "Moves for a three disk problem are" << std::endl;
    towersOfHanoi(3,1,2,3);
}
/*
Move top disk from tower 1 to top of tower 2
Move top disk from tower 1 to top of tower 3
Move top disk from tower 2 to top of tower 3
Move top disk from tower 1 to top of tower 2
Move top disk from tower 3 to top of tower 1
Move top disk from tower 3 to top of tower 2
Move top disk from tower 1 to top of tower 2
*/
