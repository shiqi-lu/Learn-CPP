#include <iostream>
#include <string>

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <boost/assign.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

void boost_unordered_set()
{
    using namespace boost::assign;

    std::cout << "============ unordered_set: ============" << std::endl;

    boost::unordered_set<int> s = (list_of(1),2,3,4,5);

    BOOST_FOREACH(int x, s) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    s.clear();
    std::cout << s.empty() << std::endl;

    s.insert(8);
    s.insert(45);
    std::cout << s.size() << std::endl;
    std::cout << *s.find(8) << std::endl;

    s.erase(45);
/*
output:
============ unordered_set: ============
5 4 3 2 1 
1
2
8
*/
}

void boost_unordered_map()
{
    using namespace boost::assign;

    std::cout << "============ unordered_map: ============" << std::endl;

    boost::unordered_map<int, std::string> um = 
        map_list_of(1, "one")(2, "two")(3, "three");
    um.insert(std::make_pair(10, "ten"));
    std::cout << um[10] << std::endl;
    um[11] = "eleven";
    um[15] = "fifteen";

    BOOST_AUTO(p, um.begin());
    for (p; p != um.end(); ++p) {
        std::cout << p->first << "-" << p->second << ",";
    }
    std::cout << std::endl;
    std::cout << um.size() << std::endl;
/*
output:
============ unordered_map: ============
ten
15-fifteen,11-eleven,10-ten,3-three,2-two,1-one,
6
*/
}

int main()
{
    boost_unordered_set();

    boost_unordered_map();

    return 0;
}

