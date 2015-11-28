#include <vector>
#include "printcoll.hpp"

int main()
{
    std::vector<int> v;

    v.push_back(42);
    v.push_back(13);
    v.push_back(7);
    printcoll(v);
}
/*
42 13 7
*/
