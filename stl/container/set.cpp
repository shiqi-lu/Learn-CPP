#include <iostream>
#include <set>
#include <algorithm>

void OutPut(std::set<int> &s)
{
    std::set<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        std::cout << " " << *it << ", ";
    }
    std::cout << std::endl;
}

void OutPutM(std::multiset<int> &s)
{
    std::multiset<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        std::cout << " " << *it << ", ";
    }
    std::cout << std::endl;
}

void Print(int  Ele)
{
    std::cout << Ele << ", ";
}

void init() 
{
    std::cout << "=============== init: ==============" << std::endl;
    std::set<int> s1;
    s1.insert(10);
    s1.insert(15);
    s1.insert(25);
    s1.insert(20);
    s1.insert(30);
    s1.insert(33);
    s1.insert(5);
    s1.insert(20);
    OutPut(s1);

    std::multiset<int> sm1;
    sm1.insert(10);
    sm1.insert(15);
    sm1.insert(25);
    sm1.insert(20);
    sm1.insert(30);
    sm1.insert(33);
    sm1.insert(5);
    sm1.insert(20);
    OutPutM(sm1);

/*
output:
=============== init: ==============
 5,  10,  15,  20,  25,  30,  33, 
 5,  10,  15,  20,  20,  25,  30,  33,
 */
}

void set_capacity()
{
    std::cout << "============ set capacity: ==============" << std::endl;
    typedef std::set<int> SET;
    typedef std::multiset<int> MSET;
    SET s1;
    MSET s2;
    SET::iterator it;
    MSET::iterator Mit;
    std::pair<SET::iterator, SET::iterator> p1;
    std::pair<MSET::iterator, MSET::iterator> Mp1;

    s1.insert(10);
    s1.insert(15);
    s1.insert(21);
    s1.insert(17);
    s2.insert(11);
    s2.insert(16);
    s2.insert(20);
    s2.insert(18);
    s2.insert(20);

    std::cout << "Set s1: " << std::endl;
    for_each(s1.begin(), s1.end(), Print);
    std::cout << std::endl;

    std::cout << "Multiset s2: " << std::endl;
    for_each(s2.begin(), s2.end(), Print);
    std::cout << std::endl;

    std::cout << "The size of the set s1: " << s1.size() << std::endl;
    std::cout << "The size of the multiset s2: " << s2.size() << std::endl;
    std::cout << "The max_size of the set s1: " << s1.max_size() << std::endl;
    std::cout << "The max_size of the Multiset s2: " << s2.max_size() << std::endl;
    std::cout << "The count of \'10\' in set s1: " << s1.count(10) << std::endl;
    std::cout << "The count of \'20\' in multiset s2: " << s2.count(20) << std::endl;
    it = s1.find(21);
    Mit = s2.find(18);
    std::cout << "The element with a key \'21\' is: " << *it << std::endl;
    std::cout << "The element with a key \'18\' is: " << *Mit << std::endl;

    it = s1.lower_bound(15);
    Mit = s2.lower_bound(16);
    if (it == s1.end()) {
        std::cout << "The element with a key 15 in s1 doesn't exist." << std::endl;
    } else {
        std::cout << "The element with a key 15 in s1 is: " << *it << std::endl;
    }
    if (Mit == s2.end()) {
        std::cout << "The element with a key 16 in s2 doesn't exist." << std::endl;
    } else {
        std::cout << "The element with a key 16 in s2 is: " << *Mit << std::endl;
    }

    it = s1.upper_bound(15);
    Mit = s2.upper_bound(16);
    if (it == s1.end()) {
        std::cout << "The element with a key > 15 in s1 doesnit exist." << std::endl;
    } else {
        std::cout << "The element with a key > 15 is s1 is: " << *it << std::endl;
    }
    if (Mit == s2.end()) {
        std::cout << "The element with a key > 16 in s2 doesn't exist." << std::endl;
    } else {
        std::cout << "The element with a key > 16 in s2 is: " << *Mit << std::endl;
    }

    p1 = s1.equal_range(15);
    Mp1 = s2.equal_range(16);
    if (it == s1.end()) {
        std::cout << "The element with a key >= 15 in s1 doesn't exist." << std::endl;
    } else {
        std::cout << "The element with a key = 15 in s1 is: " << *p1.first << std::endl;
        std::cout << "The element with a key > 15 in s1 is: " << *p1.second << std::endl;
    }
    if (Mit == s2.end()) {
        std::cout << "The element with a key > 16 in s2 doesn't exist." << std::endl;
    } else {
        std::cout << "The element with a key = 16 in s2 is: " << *Mp1.first << std::endl;
        std::cout << "The element with a key > 16 in s2 is: " << *Mp1.second << std::endl;
    }

/*
output:
============ set capacity: ==============
Set s1: 
10, 15, 17, 21, 
Multiset s2: 
11, 16, 18, 20, 20, 
The size of the set s1: 4
The size of the multiset s2: 5
The max_size of the set s1: 461168601842738790
The max_size of the Multiset s2: 461168601842738790
The count of '10' in set s1: 1
The count of '20' in multiset s2: 2
The element with a key '21' is: 21
The element with a key '18' is: 18
The element with a key 15 in s1 is: 15
The element with a key 16 in s2 is: 16
The element with a key > 15 is s1 is: 17
The element with a key > 16 in s2 is: 18
The element with a key = 15 in s1 is: 15
The element with a key > 15 in s1 is: 17
The element with a key = 16 in s2 is: 16
The element with a key > 16 in s2 is: 18

*/
}

int main()
{
    init();

    set_capacity();

    return 0;
}
