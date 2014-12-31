#include <iostream>
#include <deque>
#include <algorithm>

void Print(int & Ele)
{
    std::cout << Ele << " ";
}

void init()
{
    std::cout << "============== deque init: ========" << std::endl;
    // init
    std::deque<int> D1;
    std::deque<int> D2(5);
    std::deque<int> D3(10, 2), D31(10, 3);
    std::deque<int> D4(D3);
    std::deque<int> D5(D31.begin(), D31.end());

    // print
    std::cout << "D1: " << std::endl;
    for_each(D1.begin(), D1.end(), Print);
    std::cout << std::endl;
    std::cout << "D2: " << std::endl;
    for_each(D2.begin(), D2.end(), Print);
    std::cout << std::endl;
    std::cout << "D3: " << std::endl;
    for_each(D3.begin(), D3.end(), Print);
    std::cout << std::endl;
    std::cout << "D4: " << std::endl;
    for_each(D4.begin(), D4.end(), Print);
    std::cout << std::endl;
    std::cout << "D5: " << std::endl;
    for_each(D5.begin(), D5.end(), Print);
    std::cout << std::endl;

    std::cout << "the size of D2: " << D2.size() << std::endl;
    std::cout << "the maxsize of D2: " << D2.max_size() << std::endl;

    D31.resize(5, 'A');
    std::cout << "D31: " << std::endl;
    for_each(D31.begin(), D31.end(), Print);
    std::cout << std::endl;

    D31.resize(7, 0);
    std::cout << "D31:" << std::endl;
    for_each(D31.begin(), D31.end(), Print);
    std::cout << std::endl;
/*
output:
============== deque init: ========
D1: 

D2: 
0 0 0 0 0 
D3: 
2 2 2 2 2 2 2 2 2 2 
D4: 
2 2 2 2 2 2 2 2 2 2 
D5: 
3 3 3 3 3 3 3 3 3 3 
the size of D2: 5
the maxsize of D2: 4611686018427387903
D31: 
3 3 3 3 3 
D31:
3 3 3 3 3 0 0 
*/
}

int main()
{
    init();

    return 0;
}
