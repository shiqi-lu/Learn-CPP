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

void deque_assign()
{
    std::cout << "============== deque_assign: ===========" << std::endl;
    std::deque<int> D1;
    D1.push_front(0);
    D1.push_front(1);
    D1.push_front(2);
    D1.push_front(3);
    D1.push_front(4);
    D1.push_back(1);
    D1.push_back(2);
    D1.push_back(3);
    D1.push_back(4);

    std::cout << "D1:" << std::endl;
    for_each(D1.begin(), D1.end(), Print);
    std::cout << std::endl;

    D1[4] = 9;
    std::cout << "D1:" << std::endl;
    for_each(D1.begin(), D1.end(), Print);
    std::cout << std::endl;
/*
output:
============== deque_assign: ===========
D1:
4 3 2 1 0 1 2 3 4 
D1:
4 3 2 1 9 1 2 3 4
*/
}

void Out(double & Ele)
{
    std::cout.width(5);
    std::cout.precision(1);
    std::cout << std::fixed << Ele << " ";
}

void deque_iterator()
{
    std::cout << "========== deque_iterator: ============" << std::endl;
    std::deque<double>::iterator Iter;
    std::deque<double>::reverse_iterator rIter;
    std::deque<double> D1, D2, D3;
    for (int i = 0; i < 10; ++i) {
        D1.push_front(90 + i / 10.0);
    }
    std::cout << "D1: " << std::endl;
    for_each(D1.begin(), D1.end(), Out);
    std::cout << std::endl;
    Iter = D1.begin();
    double begin = *Iter;
    Iter = D1.end();
    double end = *(--Iter);

    rIter = D1.rbegin();
    double rbegin = *(rIter);
    rIter = D1.rend();
    double rend = *(--rIter);
    std::cout << "begin: " << begin << ", end: " << end
              << ", front: " << D1.front() << ", back: " << D1.back() << std::endl;
    std::cout << "reverse begin: " << rbegin 
              << " reverse end: " << rend << std::endl;

    if (D1.empty()) {
        std::cout << "deque of D1 is empty." << std::endl;
    } else {
        std::cout << "deque of D1 has " << D1.size() << " elements." << std::endl;
    }
    std::cout << "the fifth elements of D1 is: " << D1.at(5) << std::endl;


    D2.assign(6, 0);
    D3.assign(D1.begin(), D1.end());
    std::cout << "D2: " << std::endl;
    for_each(D2.begin(), D2.end(), Out);
    std::cout << std::endl;
    std::cout << "D3: " << std::endl;
    for_each(D3.begin(), D3.end(), Out);
    std::cout << std::endl;

    
/*
output:
========== deque_iterator: ============
D1: 
 90.9  90.8  90.7  90.6  90.5  90.4  90.3  90.2  90.1  90.0 
begin: 90.9, end: 90.0, front: 90.9, back: 90.0
reverse begin: 90.0 reverse end: 90.9
deque of D1 has 10 elements.
the fifth elements of D1 is: 90.4
D2: 
 0.0   0.0   0.0   0.0   0.0   0.0 
D3: 
 90.9  90.8  90.7  90.6  90.5  90.4  90.3  90.2  90.1  90.0 
*/
}

void deque_advanced()
{
    std::cout << "============ deque_advanced: ============" << std::endl;
    std::deque<double> D1, D2;
    for (int i = 0; i < 10; ++i) {
        D1.push_front(90 + i / 10.0);
    }
    std::cout << "D1: " << std::endl;
    for_each(D1.begin(), D1.end(), Out);
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        D2.push_front(80 + i / 10.0);
    }
    std::cout << "D2: " << std::endl;
    for_each(D2.begin(), D2.end(), Out);
    std::cout << std::endl;

    D1.swap(D2);
    std::cout << "After swap between D1 and D2: " << std::endl;
    std::cout << "D1: " << std::endl;
    for_each(D1.begin(), D1.end(), Out);
    std::cout << std::endl;
    std::cout << "D2: " << std::endl;
    for_each(D2.begin(), D2.end(), Out);
    std::cout << std::endl;

    D1.insert(D1.begin(), -1.0);
    D1.insert(D1.end(), -1.0);
    D1.insert(D1.begin() + 6, -0.0);
    std::cout << "After insert in D1: " << std::endl;
    std::cout << "D1: " << std::endl;
    for_each(D1.begin(), D1.end(), Out);
    std::cout << std::endl;

    D1.erase(D1.begin() + 1);
    D1.erase(D1.begin() + 10);
    std::cout << "After erase in D1: " << std::endl;
    std::cout << "D1: " << std::endl;
    for_each(D1.begin(), D1.end(), Out);
    std::cout << std::endl;

    D2.clear();
    std::cout << "After clear in D2: " << std::endl;
    std::cout << "D2: " << std::endl;
    for_each(D2.begin(), D2.end(), Out);
    std::cout << std::endl;

    std::deque<double>::iterator it = find(D1.begin(), D1.end(), 80.5);
    std::cout << "find 80.5, in D1, its index: " << (it - D1.begin()) << std::endl;

/*
============ deque_advanced: ============
D1: 
 90.9  90.8  90.7  90.6  90.5  90.4  90.3  90.2  90.1  90.0 
D2: 
 80.9  80.8  80.7  80.6  80.5  80.4  80.3  80.2  80.1  80.0 
After swap between D1 and D2: 
D1: 
 80.9  80.8  80.7  80.6  80.5  80.4  80.3  80.2  80.1  80.0 
D2: 
 90.9  90.8  90.7  90.6  90.5  90.4  90.3  90.2  90.1  90.0 
After insert in D1: 
D1: 
 -1.0  80.9  80.8  80.7  80.6  80.5  -0.0  80.4  80.3  80.2  80.1  80.0  -1.0 
After erase in D1: 
D1: 
 -1.0  80.8  80.7  80.6  80.5  -0.0  80.4  80.3  80.2  80.1  -1.0 
After clear in D2: 
D2: 

find 80.5, in D1, its index: 4
*/
}

int main()
{
    init();

    deque_assign();

    deque_iterator();

    deque_advanced();

    return 0;
}
