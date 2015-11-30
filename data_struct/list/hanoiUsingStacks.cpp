#include <iostream>
#include "arrayStack.h"

arrayStack<int> tower[4];

void moveAndShow(int n, int x, int y, int z)
{
    if (n > 0) {
        moveAndShow(n - 1, x, z, y);
        int d = tower[x].top();
        tower[x].pop();
        tower[y].push(d);
        std::cout << "Move disk " << d << " from tower "
                  << x << " to top of tower " << y << std::endl;
        moveAndShow(n - 1, z, y, x);
    }
}

void towersOfHanoi(int n)
{
    for (int d = n; d > 0; --d) {
        tower[1].push(d);
    }
    moveAndShow(n, 1, 2, 3);
}

int main()
{
    std::cout << "Moves for a three disk problem are" << std::endl;
    towersOfHanoi(3);
}
/*
Moves for a three disk problem are
Move disk 1 from tower 1 to top of tower 2
Move disk 2 from tower 1 to top of tower 3
Move disk 1 from tower 2 to top of tower 3
Move disk 3 from tower 1 to top of tower 2
Move disk 1 from tower 3 to top of tower 1
Move disk 2 from tower 3 to top of tower 2
Move disk 1 from tower 1 to top of tower 2
*/
