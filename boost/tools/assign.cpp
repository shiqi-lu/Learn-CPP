#include <string>
#include <set>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <boost/assign.hpp>
using namespace std;

void boost_assign_plus()
{
    //only use with stl container
    using namespace boost::assign; // very important

    vector<int> v;
    v += 1,2,3,4,5, 6*6;

    set<string> s;
    s += "cpp", "java", "c#", "python";

    map<int, string> m;
    m += make_pair(1, "one"), make_pair(2, "two");
}

void boost_assign_function()
{
    using namespace boost::assign;

    vector<int> v;
    push_back(v)(1)(2)(3)(4)(5);

    list<string> l;
    push_front(l)("cpp")("java")("c#")("python");

    set<double> s;
    insert(s)(3.14)(0.618)(1.732);

    map<int, string> m;
    insert(m)(1, "one")(2, "two");

    vector<int> v1;
    push_back(v1), 1,2,3,4,5;
    push_back(v1)(6),7,64/8,(9),10;

    deque<string> d;
    push_front(d)() = "cpp", "java", "c#", "python";
}

void init_assign()
{
    using namespace boost::assign;

    vector<int> v = list_of(1)(2)(3)(4)(5);

    deque<string> d =
    (list_of("power")("bomb"),"phazon","suit");

    set<int> s = (list_of(10), 20, 30, 40, 50);

    map<int, string> m = list_of(make_pair(1, "one"))(make_pair(2, "two"));

/*
 * c++11:
    vector<int> v = {1, 2, 3, 4, 5};
    deque<string> d = {"power", "bomb", "phazon", "suit"};
    set<int> s = {10, 20, 30, 40, 50};
    map<int, string> m = {{1, "one"}, {2, "two"}};
    */

    map<int, int> m1 = map_list_of(1, 2)(3, 4)(5, 6);
    map<int, string> m2 = map_list_of(1, "one")(2, "two");
}

void assign_repeat()
{
    using namespace boost::assign;
    vector<int> v = list_of(1).repeat(3, 2)(3)(4)(5);
    // v = 1,2,2,2,3,4,5
    
    multiset<int> ms;
    insert(ms).repeat_fun(5, &rand).repeat(2, 1), 10;
    // ms = x,x,x,x,x,1,1,10

    deque<int> d;
    push_front(d).range(v.begin(), v.begin() + 5);
    // d = 3,2,2,2,1
}

int main()
{
    boost_assign_plus();

    boost_assign_function();

    init_assign();

    assign_repeat();

    return 0;
}
