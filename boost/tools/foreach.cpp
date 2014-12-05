#include <iostream>
#include <vector>
#include <string>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
using namespace std;

void boost_foreach()
{
    cout << "=========== boost_foreach: ============" << endl;
    using namespace boost::assign;
    vector<int> v = (list_of(1),2,3,4,5);

    BOOST_FOREACH(int x, v) {
        cout << x << ",";
    }
    cout << endl;

    string str("boost foreach");
    BOOST_FOREACH(char & c, str) {
        cout << c << "-";
    }
    cout << endl;
/*
=========== boost_foreach: ============
1,2,3,4,5,
b-o-o-s-t- -f-o-r-e-a-c-h-
*/
}

void boost_foreach_stl()
{
    cout << "========== boost_foreach_stl: ===========" << endl;
    using namespace boost::assign;

    int ar[] = {1, 2, 3, 4, 5};
    BOOST_FOREACH(int & x, ar) {
        cout << x << " ";
    }
    cout << endl;

    map<int, string> m = map_list_of(1, "111")(2, "222")(3, "333");
    pair<int, string> x;
    BOOST_FOREACH(x, m) {
        cout << x.first << x.second << endl;
    }
/*
    vector< vector<int> > v =
            list_of( list_of(1)(2) )( list_of(3)(4) );
    BOOST_FOREACH(vector<int> & row, v) {
        BOOST_REVERSE_FOREACH(int & z, row) {
            cout << z << ",";
        }
        cout << endl;
    }*/
/*
========== boost_foreach_stl: ===========
1 2 3 4 5 
1111
2222
3333
*/
}

int main()
{
    boost_foreach();

    boost_foreach_stl();

    return 0;
}
